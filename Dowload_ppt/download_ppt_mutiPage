import requests
from lxml import etree
import os
import re
savaPath = '.\Dowload_ppt\中秋ppt'
if not os.path.exists(savaPath):
    os.mkdir(savaPath)
link = "https://www.1ppt.com/moban/zhongqiujie/"
uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}

requestData = requests.get(url=link, headers=uaAgent) # 解析网址
requestData.encoding = 'gbk'  # 解决中文乱码问题
dataGet = etree.HTML(requestData.text)

finalPageList = dataGet.xpath('//a[text()="末页"]/@href')
# print(finalPageList)
if finalPageList != []:
    re1 = re.search("(\d+).html", finalPageList[0])
    fianlPage = re1.group(1)
    # print(fianlPage)
else:
    fianlPage = 1
for page in range(1, int(fianlPage)+1):\
    # print(page)
    if page == 1:
        link = "https://www.1ppt.com/moban/zhongqiujie/"
    else:
        link = "https://www.1ppt.com/moban/zhongqiujie/" + f"ppt_zhongqiujie_{page}.html"
    # print(link)

    requestData = requests.get(url=link, headers=uaAgent) # 解析网址
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