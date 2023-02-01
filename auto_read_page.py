# 页数自动读取

import requests
from lxml import etree
import re

url1 = "https://www.jkl.com.cn/newsList.aspx?TypeId=10009"
uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}
requestData1 = requests.get(url=url1, headers=uaAgent).text  # 解析网址
dataGet1 = etree.HTML(requestData1)
finalPage = dataGet1.xpath('//a[text()="尾页"]/@href')
# print(finalPage[0])
if finalPage != []:
    re = re.search("=(\d)\&",finalPage[0])
    # print(re)
    # print(re.group(1))  # 拿到第一个括号
    totalPage = re.group(1)
else:
    totalPage = 1
print(totalPage)