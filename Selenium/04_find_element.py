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
# 1、通过标签的id值获取标签
密码 = 浏览器对象.find_element_by_id('password')
print(密码)
# 2、通过标签的id值获取多个标签列表,后面所有方法均是如此，不在一一重复 带s
密码2 = 浏览器对象.find_elements_by_id('password') 
print(密码2)
# 3.通过标签的class属性值获取标签
密码3 = 浏览器对象.find_elements_by_class_name('account-form-field')
print(密码3)
# 4.通过xpath获取
用户名 = 浏览器对象.find_element_by_xpath('//input[@id="username"]')
print(用户名)
# 5.根据标签的文本获取元素列表，精确定位
登录 = 浏览器对象.find_element_by_link_text('登录豆瓣')
print(登录)
# 5.1 获取属性值
print(登录.get_attribute('href'))
# 6.根据标签包含的文本获取元素列表，模糊定位 [加s可以查多个但是列表需遍历才能使用]
登录2 = 浏览器对象.find_elements_by_partial_link_text('豆瓣')
print(登录2)
# 7.根据标签名获取元素列表 【不常用】 切记用：elements
# 标签名 = 浏览器对象.find_elements_by_tag_name('div')
# 8.根据标签名获取元素列表
文字 = 浏览器对象.find_elements_by_tag_name('li')
print([文字.text for 文字 in 文字 ])


