import re
Remove = [
    "</?p>",
    "<ul>",
    "</ul>",
    "</li>"
]
Replace = [
    ["</?code>", "``"],
    ["</?strong>", "**"],
    ["<pre>", "```"],
    ["</pre>", "```"],
    ["&nbsp;", " "],
    ["&quot;", '"'],
    ["&lt;", "<"],
    ["<strong class=\"example\">", "### "],
    ["\*\*示例", "### 示例"],
    ["### 示例 1", "## 样例\n### 示例 1"],
    ["：\*\*", "："],
    ["\t<li>", "- "],
]
def convert(src):
    # pre内部预处理
    def remove_label_in_pre(matched):
        tmp = matched.group()
        tmp = re.sub("<[^>p]*>", "", tmp)   # 不匹配>与p
        return tmp
    src = re.sub("<pre>[\s\S]*?</pre>", remove_label_in_pre, src)   # 注意此处非贪心匹配，因为可能有多个示例
    # 可以直接删除的标签
    for curPattern in Remove:
        src = re.sub(curPattern, "", src)
    # 需要替换内容的标签
    for curPattern, curRepl in Replace:
        src = re.sub(curPattern, curRepl, src)
    return src

import requests, json
def get_problem_content(slug):
    user_agent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/81.0.4044.122 Safari/537.36"
    session = requests.Session()
    url = "https://leetcode-cn.com/graphql"
    params = {'operationName': "getQuestionDetail",
              'variables': {'titleSlug': slug},
              'query': '''query getQuestionDetail($titleSlug: String!) {
            question(titleSlug: $titleSlug) {
                questionId
                questionFrontendId
                translatedTitle
                translatedContent
                difficulty
            }
        }'''
    }
    json_data = json.dumps(params).encode('utf8')   
    headers = {'User-Agent': user_agent, 'Connection':
               'keep-alive', 'Content-Type': 'application/json',
               'Referer': 'https://leetcode-cn.com/problems/' + slug}
    resp = session.post(url, data=json_data, headers=headers, timeout=10)
    resp.encoding = 'utf8'
    content = resp.json()
    # 题目详细信息
    # print(content)
    question = content['data']['question']
    fh = open(outputFileName, 'w', encoding='utf-8')
    # fh.writelines(question['translatedContent'])
    print("questionFrontendId: " + question['questionFrontendId'])
    print("translatedTitle: " + question['translatedTitle'])
    print("difficulty: " + question['difficulty'])
    fh.writelines(question['difficulty'] + '\n')
    # fh.writelines(question['questionId'] + '. ' + question['translatedTitle'] + '\n')
    fh.writelines(question['translatedTitle'] + '\n')
    fh.writelines(convert(question['translatedContent']))
    fh.close()

# question = input("The question: ")
import sys
question = sys.argv[1]
if len(sys.argv) >= 3:
    outputFileName = sys.argv[2]
else:
    outputFileName = "res.md"
# print("Output file: " + outputFileName)
print("The question: " + question)

get_problem_content(question)

# 可用属性
# {
#   operationName: "questionData"
#   query: "query questionData($titleSlug: String!) {
#   question(titleSlug: $titleSlug) {
#     questionId
#     questionFrontendId
#     boundTopicId
#     title
#     titleSlug
#     content
#     translatedTitle
#     translatedContent
#     isPaidOnly
#     difficulty
#     likes
#     dislikes
#     isLiked
#     similarQuestions
#     contributors {
#       username
#       profileUrl
#       avatarUrl
#       __typename
#     }
#     langToValidPlayground
#     topicTags {
#       name
#       slug
#       translatedName
#       __typename
#     }
#     companyTagStats
#     codeSnippets {
#       lang
#       langSlug
#       code
#       __typename
#     }
#     stats
#     hints
#     solution {
#       id
#       canSeeDetail
#       __typename
#     }
#     status
#     sampleTestCase
#     metaData
#     judgerAvailable
#     judgeType
#     mysqlSchemas
#     enableRunCode
#     envInfo
#     book {
#       id
#       bookName
#       pressName
#       source
#       shortDescription
#       fullDescription
#       bookImgUrl
#       pressImgUrl
#       productUrl
#       __typename
#     }
#     isSubscribed
#     isDailyQuestion
#     dailyRecordStatus
#     editorType
#     ugcQuestionId
#     __typename
#   }
# }
# "
#   variables: {titleSlug: "merge-two-sorted-lists"}
# }