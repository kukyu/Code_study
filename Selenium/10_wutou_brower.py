from selenium import webdriver
# 实现无头浏览器
from selenium.webdriver.chrome.options import Options
# 实现规避检测
from selenium.webdriver import ChromeOptions
# 实现无头浏览器参数
chrome_options = Options()
chrome_options.add_argument('--headless')
chrome_options.add_argument('--disable-gpu')
# 实现规避检测
option = ChromeOptions()
option.add_experimental_option('excludeSwitches',['enable-automation'])

浏览器对象 = webdriver.Chrome(chrome_options=chrome_options,options=option)
浏览器对象.get('https://www.baidu.com')
print(浏览器对象.page_source)

# 注：PhantomJs停止更新了，不建议使用