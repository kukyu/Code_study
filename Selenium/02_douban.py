# 用于测试，selenium闪退

# 导包
from selenium import webdriver
# 获取[浏览器]的实例化对象
浏览器对象 = webdriver.Chrome()
# 最大化浏览器
浏览器对象.maximize_window()
# 使用浏览器打开网址
浏览器对象.get("https://www.douban.com/")
# 定位iframe这个元素
iframe_元素 = 浏览器对象.find_element_by_tag_name('iframe')
# 切换iframe
浏览器对象.switch_to.frame(iframe_元素)
# 定位元素（密码登录）
元素 = 浏览器对象.find_element_by_xpath("//li[text()='密码登录']")
元素.click()
# 定位并输入用户名
用户名 = 浏览器对象.find_element_by_xpath('//input[@id="username"]')
用户名.clear()
用户名.send_keys('15701168930')
# 定位并输入密码  id是唯一的
密码 = 浏览器对象.find_element_by_id('password')
密码.clear()
密码.send_keys('viewsonic')
# 定位登录并点击
登录 = 浏览器对象.find_element_by_xpath("//a[text()='登录豆瓣']")
登录.click()

