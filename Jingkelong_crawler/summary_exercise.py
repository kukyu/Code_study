import requests
from lxml import etree
import re
import os

url1 = "https://www.jkl.com.cn/newsList.aspx?TypeId=10009"
uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}
requestData = requests.get(url=url1, headers=uaAgent).text  # 解析网址
dataGet = etree.HTML(requestData)
projectName = dataGet.xpath('//div[@class = "infoLis"]//a/text()')
projectLink = dataGet.xpath('//div[@class = "infoLis"]//@href')
# print(projectName)
# print(projectLink)
projectName = [projectName.strip() for projectName in projectName]  # 去除空格
# print(projectName)
projectLink = ['https://www.jkl.com.cn/' +
               projectLink for projectLink in projectLink]
# print(projectLink)
dict1 = dict(zip(projectName, projectLink))
# print(dict1)
for pName, pLink in dict1.items():
    # print(pLink)
    pName = pName.replace("/", ".")
    pName = pName.replace("露...", "露报表")
    pName = pName.replace("运...", "运作告知书")
    pAddr = ".\Jingkelong_crawler\Summary_doc\\" + pName
    # print(pName)
    if not os.path.exists(pAddr):
        os.mkdir(pAddr)
        print(pAddr)
    requestData = requests.get(url=pLink, headers=uaAgent).text
    dataGet = etree.HTML(requestData)
    finalPage = dataGet.xpath('//a[text()="尾页"]/@href')
    # print(finalPage)
    # 正则表达式提取
    if finalPage != []:
        current = re.search("t=(\d+)\&", finalPage[0])
        # print(re1)
        # print(re1.group(1))  # 拿到第一个括号
        totalPage = current.group(1)
    else:
        totalPage = 1
    typeId = re.search("d=(\d+)", pLink)
    typeId = typeId.group(1)
    # print(typeId)
    for page in range(1,int(totalPage)+1):
        url2 = "https://www.jkl.com.cn/newsList.aspx?current={}&TypeId={}".format(page, typeId)
        # print(url2)
        requestData = requests.get(url=url2, headers=uaAgent).text  # 解析网址
        dataGet = etree.HTML(requestData)
        docLink = dataGet.xpath('//div[@class = "newsLis"]//li//@href')  # 获取文档所在网址 黄颜色加@
        docName = dataGet.xpath('//div[@class = "newsLis"]//li/a/text()')  # 获取文档名称  紫不加
        # print(docLink)
        # print(docName)

        # 去除空格和换行
        newDocName = []
        for name in docName:
            name = name.strip()
            newDocName.append(name)
        # print(newDocName)
        if all(docLink):
            docLink = ['http://www.jkl.com.cn' + i for i in docLink]
            # print(docLink)
            docDict = dict(zip(newDocName, docLink))  # 名称和网址对应的字典
            # print(docDict)
            # 遍历键值
            for k, v in docDict.items():
                docType = v.split(".")[-1]
                # print(docType)
                k = k.replace("/", ".") # 替换
                docData = requests.get(url=v, headers=uaAgent).content  # 获取文档内容
                docAddr = pAddr + '//' + k + '.' + docType  # 保存文件地址
                # print(docAddr)
                # # 二进制数据写入本地
                with open(docAddr, 'wb') as ret: 
                    ret.write(docData)           
                    print(k, "下载成功！")
