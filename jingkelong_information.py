import requests
from lxml import etree
import pandas as pd

myUrl = "https://www.jkl.com.cn/shop.aspx"

uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}

# 1.拿取每个城区网址
requestData = requests.get(url=myUrl, headers=uaAgent).text  # 响应数据
# print(requestData)
dataGet = etree.HTML(requestData)  # 解析
cityArea = dataGet.xpath('//div[@class="infoLis"]//@href')  # 城区
# print(cityArea)
for area in cityArea:
    url2 = 'http://www.jkl.com.cn/' + area
    # print(url2)
    requestData1 = requests.get(url=url2, headers=uaAgent).text  # 拿取地区内容
    dataGet1 = etree.HTML(requestData1)
    shopName = dataGet1.xpath('//span[@class = "con01"]/text()')
    # print(shopName)
    shopAddr = dataGet1.xpath('//span[@class = "con02"]/text()')  # 地址
    shopTel = dataGet1.xpath('//span[@class = "con03"]/text()')  # 电话
    shopTime = dataGet1.xpath('//span[@class = "con04"]/text()')  # 营业时间
    # print(shopTel)
    # 去除空格和换行
    newShopName = []
    for name in shopName:
        newData = name.strip()
        newShopName.append(newData)
    # print(newShopName)
    data = pd.DataFrame({'店名':newShopName, '地址':shopAddr, '电话':shopTel, '营业时间':shopTime})
    data.to_csv(".\店铺信息1.csv", index = False, header=0, mode='a', encoding='ANSI')



