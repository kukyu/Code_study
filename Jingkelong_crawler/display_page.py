import requests
from lxml import etree
import re

url1 = "https://www.jkl.com.cn/shop.aspx"
uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}
requestData1 = requests.get(url=url1, headers=uaAgent).text  # 解析网址
dataGet1 = etree.HTML(requestData1)
areaName = dataGet1.xpath('//div[@class="infoLis"]//a/text()')
areaLink = dataGet1.xpath('//div[@class="infoLis"]//@href')
# print(areaName[0])
# print(areaLink)
for i in range(0, len(areaName)):
    url2 = 'https://www.jkl.com.cn/' + areaLink[i]
    # print(url2)
    requestData2 = requests.get(url=url2, headers=uaAgent).text  # 解析网址
    dataGet2 = etree.HTML(requestData2)
    finalPage = dataGet2.xpath('//a[text()="尾页"]/@href')
    # print(finalPage)
    # 正则表达式提取
    if finalPage != []:
        re = re.search("=(\d+)\&", finalPage[0])
        # print(re)
        # print(re.group(1))  # 拿到第一个括号
        totalPage = re.group(1)
    else:
        totalPage = 1
    print(f'{areaName[i]}, {url2}, 总页数{totalPage}')
