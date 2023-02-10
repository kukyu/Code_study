import requests
import json
import pandas as pd
print("""
    1-纪录片；2-传记；3-犯罪；4-历史；5-动作；
    6-情色；7-歌舞；8-儿童；10-悬疑；11-剧情；
    12-灾难；13-爱情；14-音乐；15-冒险；16-奇幻；
    17-科幻；18-运动；19-惊悚；20-恐怖；22-战争；
    23-短篇；24-喜剧；25-动画；26-同性；27-西部；
    28-家庭；29-武侠；30-古装；31-黑色电影
""")
# moviesType = input("请输入电影类型序号：")
moviesType = 1
# moviesRank = input("您想查看排名前多少位的电影：")
moviesRank = 10

uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}

link = "https://movie.douban.com/j/chart/top_list"
data = {
    "type": moviesType,
    "interval_id": '100:90',
    "action": ' ',
    "start": '0',
    "limit": moviesRank
}

#  ?type=11&interval_id=100%3A90&action=&start=0&limit=1
requestData = requests.get(url=link, headers=uaAgent, params=data).text
# print(requestData)
# print(type(requestData))
dictList = json.loads(requestData)
# print(type(dictList))
# print(dictList)
moviesName= [zd["title"] for zd in dictList]    # ip被禁了
moviesScore= [zd["score"] for zd in dictList]  
moviesType= [zd["types"] for zd in dictList]  
data = pd.DataFrame({"名称":moviesName, "评分" :moviesScore, "类型" : moviesType})
data.index += 1
data.to_excel(".\Douban_data\豆瓣电影.xlsx")


