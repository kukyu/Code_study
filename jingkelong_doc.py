import requests
from lxml import etree
import os
if not os.path.exists('E:\\Python\\Python_crawler\\Get_doc'):
    os.mkdir('E:\\Python\\Python_crawler\\Get_doc')
url1 = "https://www.jkl.com.cn/newsList.aspx?current=1&TypeId=10009"
uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}

list1 = []
list2 = []
for page in range(1, 4):
    url2 = "https://www.jkl.com.cn/newsList.aspx?current={}&TypeId=10009".format(
        page)
    # print(url2)
    requestData1 = requests.get(url=url2, headers=uaAgent).text  # 解析网址
    dataGet1 = etree.HTML(requestData1)
    docLink = dataGet1.xpath(
        '//div[@class = "newsLis"]//li//@href')  # 获取文档所在网址 黄颜色加@
    docName = dataGet1.xpath(
        '//div[@class = "newsLis"]//li/a/text()')  # 获取文档名称  紫不加
    # print(picturesLink)
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
# print(list1)
finalDocLink = list1
finalDocName = list2
docDict = dict(zip(finalDocName, finalDocLink))  # 名称和网址对应的字典
# print(docDict)
# 遍历键值
for k, v in docDict.items():
    docType = v.split(".")[-1]
    # print(docType)
    docData = requests.get(url=v, headers=uaAgent).content  # 获取文档内容
    docAddr = "E:\\Python\\Python_crawler\\Get_doc\\" + k + '.' + docType  # 保存文件地址
    # 二进制数据写入本地
    with open(docAddr, 'wb') as ret:
        ret.write(docData)
        print(k, "下载成功！")



