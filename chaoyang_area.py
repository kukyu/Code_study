import requests
from lxml import etree
import pandas as pd

url2 = "https://www.jkl.com.cn/shopLis.aspx?TypeId=10045"
uaAgent = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}

for page in range(1,4):
    changePage = {'__EVENTARGUMENT': page,
                    '__EVENTTARGET': 'AspNetPager1'}
    requestData1 = requests.get(url=url2, headers=uaAgent, data=changePage).text
    dataGet1 = etree.HTML(requestData1)

    shopName = dataGet1.xpath('//span[@class = "con01"]/text()') 
    shopAddr = dataGet1.xpath('//span[@class = "con02"]/text()')  # 地址
    shopTel = dataGet1.xpath('//span[@class = "con03"]/text()')  # 电话
    shopTime = dataGet1.xpath('//span[@class = "con04"]/text()')  # 营业时间
    data = pd.DataFrame({'店名':shopName, '地址':shopAddr, '电话':shopTel, '营业时间':shopTime})
    data.to_csv(".\店铺信息2.csv", index = False, header=0, mode='a', encoding='ANSI')
