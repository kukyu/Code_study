from selenium import webdriver
import time
浏览器对象 = webdriver.Chrome()
浏览器对象.get("https://www.douban.com/")
# 找到图片并且点击
浏览器对象.find_element_by_xpath('//*[@id="anony-sns"]/div/div[3]/div/div[1]/ul/li[2]/div/a/img').click()
time.sleep(5)
浏览器对象.back() # 回退
time.sleep(5)
浏览器对象.forward() # 前进