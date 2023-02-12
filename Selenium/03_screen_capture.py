from selenium import webdriver
import time
# 获取[浏览器]的实例化对象
浏览器对象 = webdriver.Chrome()
# 最大化浏览器
浏览器对象.maximize_window()
# 使用浏览器打开网址
浏览器对象.get("https://www.baidu.com/")
# 页面的基本操作 [点击，输入]
浏览器对象.find_element_by_id('kw').send_keys('孙兴华B站')
浏览器对象.find_element_by_id('su').click()
# 延时
time.sleep(3)
# 对当前网页截屏
浏览器对象.save_screenshot('./Selenium/11.png')
# 获取渲染后的全部数据[就是点击检查后的所有代码]
# print(浏览器对象.page_source)
# 获取网页的cookies值
print(浏览器对象.get_cookies())
# 获取当前页面的URL
print(浏览器对象.current_url)
