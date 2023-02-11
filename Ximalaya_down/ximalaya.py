## 爬取失败，网址变更

import requests
from lxml import etree
import re
link = "https://www.ximalaya.com/album/9723091/"
uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}
requestData = requests.get(url=link, headers=uaAgent)
# print(requestData)
dataGet = etree.HTML(requestData.text)
totalPage = dataGet.xpath('//*[@id="anchor_sound_list"]/div[2]/div/nav/ul/li[5]/a/text()')
print(totalPage)
# for i in range(1, int(totalPage)+1):
#     if i == 1:
#         print()