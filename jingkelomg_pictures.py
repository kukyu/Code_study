import requests
from lxml import etree
import os
if not os.path.exists('E:\\Python\\Python_crawler\\Get_pictures'):
    os.mkdir('E:\\Python\\Python_crawler\\Get_pictures')
url1 = "https://www.jkl.com.cn/phoLis.aspx"
uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}

list1 = []
for page in range(1, 4):
    url2 = "https://www.jkl.com.cn/phoLis.aspx?current={}".format(page)
    # print(url2)
    requestData1 = requests.get(url=url2, headers=uaAgent).text  # 解析网址
    dataGet1 = etree.HTML(requestData1)
    picturesLink = dataGet1.xpath('//div[@class = "proLis"]//@src')
    # print(picturesLink)
    list1 = list1 + picturesLink  # 三页的列表合并为一个列表
# print(list1)
picturesLink2 = list1
for i in picturesLink2:
    url3 = "http://www.jkl.com.cn" + i
    # print(url3)
    picturesData = requests.get(url=url3, headers=uaAgent).content  # 获取图片内容
    picName = url3.split("/")[-1]
    picAddr = "E:\\Python\\Python_crawler\\Get_pictures\\" + picName  # 保存文件地址
    print(picAddr)
    with open(picAddr, 'wb') as ret:
        ret.write(picturesData)
        print(picName, "下载成功！")
