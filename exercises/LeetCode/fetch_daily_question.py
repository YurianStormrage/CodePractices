import requests
import subprocess
import datetime

# GraphQL 查询
query = """
query CalendarTaskSchedule($days: Int!) {
  calendarTaskSchedule(days: $days) {
    contests {
      id
      name
      slug
      progress
      link
      premiumOnly
    }
    dailyQuestions {
      id
      name
      slug
      progress
      link
      premiumOnly
    }
    studyPlans {
      id
      name
      slug
      progress
      link
      premiumOnly
    }
  }
}
"""

# 请求体
variables = {"days": 0}
payload = {
    "query": query,
    "variables": variables,
    "operationName": "CalendarTaskSchedule"
}

# 发送 POST 请求
response = requests.post("https://leetcode.cn/graphql/", json=payload)

# 解析 JSON 响应
data = response.json()

# 提取 "slug"
slug = data["data"]["calendarTaskSchedule"]["dailyQuestions"][0]["slug"]
# 提取 "id"
id = data["data"]["calendarTaskSchedule"]["dailyQuestions"][0]["id"]
# 提取 "name"
name = data["data"]["calendarTaskSchedule"]["dailyQuestions"][0]["name"]

# 使用subprocess调用另一个Python脚本
subprocess.run(['python', 'leetcode_crawler.py', slug])

# 获取今天的日期
today = datetime.datetime.today().strftime('%Y/%m/%d')

# 读取文件内容
with open('readme.md', 'r', encoding='utf-8') as file:
    lines = file.readlines()

# 找到"## Calendar"小节的位置
calendar_index = None
for i, line in enumerate(lines):
    if line.strip() == "## Calendar":
        calendar_index = i
        break

# 如果找到了"## Calendar"小节
if calendar_index is not None:
    # 找到小节下的列表的起始位置
    list_start_index = calendar_index + 1
    while list_start_index < len(lines) and not lines[list_start_index].strip().startswith("- "):
        list_start_index += 1

    # 插入新内容到列表的最前端
    new_lines = [
        f"- {today}\n",
        f"  - [{id}. {name}]({id}/readme.md)\n"
    ]
    lines[list_start_index:list_start_index] = new_lines

    # 写回文件
    with open('readme.md', 'w', encoding='utf-8') as file:
        file.writelines(lines)

else:
    print("未找到 '## Calendar' 小节")