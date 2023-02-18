import asyncio
import aiohttp
from lxml import etree
import os
PATH = '.\Coroutine_download\Doc'
if not os.path.exists(PATH):
    os.mkdir(PATH)


async def GetData():
    uaAgent = {
        'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}
    async with aiohttp.ClientSession() as session:
        list1 = []
        list2 = []
        for page in range(1, 4):
            url2 = "https://www.jkl.com.cn/newsList.aspx?current={}&TypeId=10009".format(
                page)
            # print(url2)
            async with await session.get(url=url2, headers=uaAgent) as requestObj:
                # print(requestData)
                requestData = await requestObj.text()
                dataGet = etree.HTML(requestData)
                docLink = dataGet.xpath(
                    '//div[@class = "newsLis"]//li//@href')  # 获取文档所在网址 黄颜色加@
                docName = dataGet.xpath(
                    '//div[@class = "newsLis"]//li/a/text()')  # 获取文档名称  紫不加
                # 去除空格和换行
                newDocName = []
                for name in docName:
                    name = name.strip()
                    newDocName.append(name)
                # print(newDocName)
                # 补充完整网址
                newDocLink = []
                for i in docLink:
                    url3 = "http://www.jkl.com.cn" + i  # 网址补充完整
                    newDocLink.append(url3)   # 新的pdf链接网址
                list1 = list1 + newDocLink  # 三页的列表合并为一个列表
                list2 = list2 + newDocName  # 同上
        return list2, list1


async def DownData(name, link):
    print("开始下载", name)
    docType = link.split(".")[-1]
    # print(docType)
    async with aiohttp.ClientSession() as session:
        async with await session.get(url=link) as docObj:
            docData = await docObj.read()
            docAddr = PATH + '/' + name + '.' + docType  # 保存文件地址
            # print(docAddr)
            # 二进制数据写入本地
            with open(docAddr, 'wb') as ret:
                ret.write(docData)
                print(name, "下载成功！")

# myTuple = asyncio.run(GetData())
loop = asyncio.get_event_loop()
myTuple = loop.run_until_complete(GetData())
docName = myTuple[0]
docLink = myTuple[1]
# print(docName)
# print(docLink)
taskObj = [DownData(name, link) for name, link in zip(docName, docLink)]
# loop = asyncio.get_event_loop()
# loop.run_until_complete(asyncio.wait(taskObj))
asyncio.run(asyncio.wait(taskObj))


