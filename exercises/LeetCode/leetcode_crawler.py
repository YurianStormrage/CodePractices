# 拉取题目描述并转换为markdown格式

import os
import re
import json
import requests

def get_question_content(question_id):
    url = 'https://leetcode-cn.com/graphql'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) \
            AppleWebKit/537.36 (KHTML, like Gecko) \
            Chrome/81.0.4044.122 Safari/537.36',
        'Connection': 'keep-alive',
        'Content-Type': 'application/json',
        'Referer': 'https://leetcode-cn.com/problems/' + question_id
    }
    data = {
        'operationName': 'getQuestionDetail',
        'variables': {'titleSlug': question_id},
        'query': '''query getQuestionDetail($titleSlug: String!) {
            question(titleSlug: $titleSlug) {
                questionFrontendId
                translatedTitle
                translatedContent
                difficulty
            }
        }'''
    }
    response = requests.post(url, headers=headers, json=data, timeout=10)
    if response.status_code != 200:
        raise Exception('Failed to get question content.')
    content = json.loads(response.text)['data']['question']
    return content

def replace_content_with_md(content):
    def remove_label_in_pre(matched):
        tmp = matched.group()
        tmp = re.sub(r'<[^>p]*>', '', tmp)
        return tmp
    def replace_with_math_or_code(matched):
        tmp = matched.group()
        flag = False
        if '<sub>' in tmp:
            tmp = re.sub(r'<sub>(.*?)</sub>', r'_{\1}', tmp)
            flag = True
        if '<sup>' in tmp:
            tmp = re.sub(r'<sup>(.*?)</sup>', r'^{\1}', tmp)
            flag = True
        if flag:
            tmp = re.sub(r'<code>(.*?)</code>', r'$\1$', tmp)
        else:
            tmp = re.sub(r'<code>(.*?)</code>', r'`\1`', tmp)
        return tmp
    replaces = [
        [r'<pre>.*?</pre>', remove_label_in_pre], # 替换pre内部的标签
        [r'<strong>(.*?)</strong>', r'**\1**'],
        [r'<code>.*?</code>', replace_with_math_or_code],
        [r'<em>(.*?)</em>', r'*\1*'],
        [r'<pre>(.*?)</pre>', r'```\n\1```'],
        [r'<p>(.*?)</p>', r'\1'],
        [r'<br/>', r'\n'],
        [r'<a href="(.*?)">(.*?)</a>', r'[\2](\1)'],
        [r'<strong class="example">(.*?)</strong>', r'### \1'],
        ['&nbsp;', ' '],
        ['&quot;', '"'],
        ['&lt;', '<'],
        ['&gt;', '>'],
        [r'<ul>(.*?)</ul>', r'\1'],
        [r'[\t]<li>(.*?)</li>', r'- \1'],
        [r'\*\*(示例 \d+)：?\*\*', r'### \1'],
        [r'### 示例 1', r'## 样例\n### 示例 1'],
        [r'\*\*提示：\*\*', r'## 限制\n'],
        [r'([\t ]*\n){3,}', r'\n'],
    ]
    for pattern, repl in replaces:
        content = re.sub(pattern, repl, content, flags=re.S)
    return content

import sys
if len(sys.argv) != 2:
    print('Usage: python leetcode_crawler.py <question_id>')
    exit(1)
slug = sys.argv[1]
content = get_question_content(slug)
print(content)
id = content['questionFrontendId']
title = content['translatedTitle']
difficulty = content['difficulty']
content_md = replace_content_with_md(content['translatedContent'])

out = os.path.join(os.path.dirname(__file__), id, 'readme.md')

out_dir = os.path.dirname(out)
if not os.path.exists(out_dir):
    os.makedirs(out_dir)

with open(out, 'w', encoding='utf-8') as f:
    f.write(
        '---\n' +
        'title: ' + title + '\n' +
        'difficulty: ' + difficulty + '\n' +
        'date: ' + os.popen('date \'+%Y-%m-%d %H:%M:%S\'').read() +
        'url: https://leetcode-cn.com/problems/' + slug + '\n' +
        'tags:\n' +
        '    - \n' +
        '---\n' +
        '# ' + id + '. ' + title + '\n\n' +
        '## 描述\n\n' +
        content_md + '\n' +
        '## [思考](code.cpp)\n'
    )

with open(os.path.join(out_dir, 'code.cpp'), 'w', encoding='utf-8') as dst, \
    open(os.path.join(os.path.dirname(__file__), 'code.cpp'), 'r', encoding='utf-8') as src:
    dst.write(src.read())