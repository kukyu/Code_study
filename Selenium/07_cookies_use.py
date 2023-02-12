from selenium import webdriver
import requests
from lxml import etree

浏览器对象 = webdriver.Chrome()
浏览器对象.get("https://so.gushiwen.cn/user/login.aspx?from=http://so.gushiwen.cn/user/collect.aspx")
用户名 = 浏览器对象.find_element_by_id('email')
用户名.clear()
用户名.send_keys('2963@qq.com')  # 输入用户名
密码 = 浏览器对象.find_element_by_id('pwd')
密码.clear()
密码.send_keys('yy')  # 输入密码
输入 = input("请输入验证码：")
验证码 = 浏览器对象.find_element_by_id('code')
验证码.clear()
验证码.send_keys(输入)  # 输入验证码
登录 = 浏览器对象.find_element_by_id('denglu')
登录.click()  # 登录
二维码 = 浏览器对象.find_element_by_id('close')  # 关闭公众号广告
二维码.click()
网址 = 浏览器对象.current_url
UA伪装 = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:109.0) Gecko/20100101 Firefox/109.0'}
cookies = 浏览器对象.get_cookies()
cookie_dict = {}
for i in cookies:  # 列表中字典变成一个字典
    cookie_dict[i["name"]] = i["value"]
# print(cookie_dict)
响应数据 = requests.get(url=网址, headers=UA伪装, cookies=cookie_dict).text
解析 = etree.HTML(响应数据)
名称 = 解析.xpath('//div[@class="sons"]//a//text()')
名称 = [''.join(名称[i:i+2]) for i in range(0, len(名称), 2)]
网址 = 解析.xpath('//div[@class="sons"]//a/@href')
网址 = ['https://so.gushiwen.cn/'+网址 for 网址 in 网址]
# 字典 = dict(zip(名称, 网址))
# for 名称, 网址 in 字典.items():
#     print(名称, 网址)
