import requests
import json
import pandas as pd



# productId= input("请输入商品编码：")
productId = 10064193589169
# commmentPage = int(input("请输入要下载评论的页数："))
commmentPage = 1
uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}
link = f'https://club.jd.com/comment/productPageComments.action?callback=fetchJSON_comment98&productId={productId}&score=0&sortType=5&page={commmentPage-1}&pageSize=10&isShadowSku=0&fold=1'

requestData = requests.get(url=link, headers=uaAgent).text
requestData = requestData.replace('fetchJSON_comment98(', "")
requestData = requestData.replace(');', "")
# print(requestData)
dictData = json.loads(requestData)
# print(dictData)
commentList = dictData['comments']
# print(commentList)
content  = [comment["content"] for comment in commentList]  # 评论内容
# print(content)
color  = [comment["productColor"] for comment in commentList]  # 颜色
type  = [comment["productSize"] for comment in commentList] #型号
# print(color)
# print(type)
myData = pd.DataFrame({"评价":content, "颜色": color, "型号" : type})
myData.index += 1
myData.to_excel("./Jingdong_comments/京东评论.xlsx")
