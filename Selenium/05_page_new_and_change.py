# # 页面切换和返回
# # 导包
# from selenium import webdriver
# # 获取[浏览器]的实例化对象
# 浏览器对象 = webdriver.Chrome()
# # 最大化浏览器
# 浏览器对象.maximize_window()
# # 使用浏览器打开网址
# 浏览器对象.get("https://www.douban.com/")
# # 定位并点击电影[注意不要加s否则要遍历]
# 浏览器对象.find_element_by_xpath('//*[@id="anony-nav"]/div[1]/ul/li[2]/a').click()
# # 获取当前所有的页面【列表】
# 页面 = 浏览器对象.window_handles
# # 根据页面列表下标进行切换
# 浏览器对象.switch_to.window(页面[0])


# 二、新建与切换
from selenium import webdriver
import time
浏览器对象 = webdriver.Chrome()
浏览器对象.get("https://www.douban.com/")
time.sleep(2)
浏览器对象.execute_script("window.open('https://www.163.com/')")        # 打开新页面
time.sleep(2)
浏览器对象.execute_script("window.open('https://www.jd.com/')")         # 打开新页面
time.sleep(2)
浏览器对象.execute_script("window.open('https://changde.58.com/')")     # 打开新页面
# 获取当前所有的页面【列表】
页面 = 浏览器对象.window_handles
# 根据页面列表下标进行切换
浏览器对象.switch_to.window(页面[0])
