import requests
from lxml import etree
import os
savaPath = '.\Dowload_ppt\生日ppt'
if not os.path.exists(savaPath):
    os.mkdir(savaPath)
url1 = "https://www.1ppt.com/moban/shengri/"
uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}

requestData = requests.get(url=url1, headers=uaAgent) # 解析网址
requestData.encoding = 'gbk'
dataGet = etree.HTML(requestData.text)
# print(dataGet)
docName = dataGet.xpath('//ul[@class="tplist"]//@alt')
# print(docName)
docLink = dataGet.xpath('//ul[@class="tplist"]/li/a/@href')
# print(docLink)
docLink = ["https://www.1ppt.com" + i for i in docLink]
# print(docLink)
linkList = []
for i in docLink:
    requestData = requests.get(url=i, headers=uaAgent).text # 解析网址
    dataGet = etree.HTML(requestData)
    # print(dataGet)
    docLink = dataGet.xpath('//ul[@class="downurllist"]/li/a/@href')
    # print(docLink)
    docLink = ["https://www.1ppt.com" + i for i in docLink]
    linkList.extend(docLink)
#     # print(docLink)
# print(linkList)
dict1 = dict(zip(docName, linkList))
# print(dict1)
for docName,docLink in dict1.items():
    requestData = requests.get(url=docLink, headers=uaAgent).text
    dataGet = etree.HTML(requestData)
    downloadUrl = dataGet.xpath('//ul[@class="downloadlist"]/li/a/@href')
    # print(downloadUrl)
    docData = requests.get(url=downloadUrl[0], headers=uaAgent).content
    docType = downloadUrl[0].split('.')[-1]
    docAddr = savaPath + "\\" + docName + "." + docType
    # print(docAddr)
    with open(docAddr, "wb") as doc:
        doc.write(docData)
        print(docName, "下载成功！")