from selenium import webdriver
import requests
import time
from PIL import Image # 需要安装【pip3 install Image】,裁剪
from selenium.webdriver import  ActionChains # 动作链
# 1. 粘贴【超级鹰】上半部分代码
from hashlib import md5
class Chaojiying_Client(object):

    def __init__(self, username, password, soft_id):
        self.username = username
        password =  password.encode('utf8')
        self.password = md5(password).hexdigest()
        self.soft_id = soft_id
        self.base_params = {
            'user': self.username,
            'pass2': self.password,
            'softid': self.soft_id,
        }
        self.headers = {
            'Connection': 'Keep-Alive',
            'User-Agent': 'Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0)',
        }

    def PostPic(self, im, codetype):
        """
        im: 图片字节
        codetype: 题目类型 参考 http://www.chaojiying.com/price.html
        """
        params = {
            'codetype': codetype,
        }
        params.update(self.base_params)
        files = {'userfile': ('ccc.jpg', im)}
        r = requests.post('http://upload.chaojiying.net/Upload/Processing.php', data=params, files=files, headers=self.headers)
        return r.json()

    def ReportError(self, im_id):
        """
        im_id:报错题目的图片ID
        """
        params = {
            'id': im_id,
        }
        params.update(self.base_params)
        r = requests.post('http://upload.chaojiying.net/Upload/ReportError.php', data=params, headers=self.headers)
        return r.json()

# 2.使用selenium打开登录页面点击帐号登录,输入用户名和密码，并截图 【切记最大化】
浏览器对象 = webdriver.Chrome()
浏览器对象.maximize_window() # 最大化浏览器
浏览器对象.get('https://kyfw.12306.cn/otn/resources/login.html')
浏览器对象.find_element_by_xpath('//a[text()="账号登录"]').click() # 点击帐号登录
浏览器对象.find_element_by_id("J-userName").send_keys('1391234567') # 用户名
浏览器对象.find_element_by_id("J-password").send_keys('1234') # 密码
浏览器对象.save_screenshot('.\Selenium\py12306.png') #  【截图】
# 3.确定验证码图片区域位置和大小
验证码图片 = 浏览器对象.find_element_by_xpath('//*[@id="J-loginImg"]')
坐标 = 验证码图片.location  # location:左上角坐标(x和y)
# print(坐标)
长和宽 = 验证码图片.size # size:长和宽
# print(长和宽)
# 4.验证码图片左上角和右下角坐标
左上到右下两点坐标 = (int(坐标['x']),int(坐标['y']),int(坐标['x']+长和宽['width']),int(坐标['y']+长和宽['height']))
# print(左上到右下两点坐标)
# 5.实例化一个Image对象 【加载截图，指定裁剪后的图片名字】
打开图片 = Image.open('.\Selenium\py12306.png')
验证码图片的名字 = '.\Selenium\yanzhengma.png'
# 6.使用crop根据指定区域（左上到右下两点坐标）进行图片的裁剪
裁剪 = 打开图片.crop(左上到右下两点坐标)
裁剪.save(验证码图片的名字)
# 7.使用【超级鹰】识别验证码图片，粘贴【超级鹰】第二部分
chaojiying = Chaojiying_Client('jjxx2006', 'jjxx2008', '906707')	#用户中心>>软件ID 生成一个替换 96001
im = open('.\Selenium\yanzhengma.png', 'rb').read()			 #本地图片文件路径 来替换 a.jpg 有时WIN系统须要//
验证码坐标 = chaojiying.PostPic(im, 9004)['pic_str']
print(chaojiying.PostPic(im, 9004)['pic_str'])
# 8. 把坐标变成[ [25,18] , [53,28] ] 或 [ [25,18] ]
if '|' in 验证码坐标:
    总列表 = [ [int(i.split(',')[j]) for i in 验证码坐标.split('|')] for j in range(len(验证码坐标.split('|'))) ]
else:
    总列表 = [[int(i) for i in 验证码坐标.split(',')]]
# print(验证码列表)
# 遍历列表使用动作链
for 小列表 in 总列表:
    # print(小列表)
    x = 小列表[0]
    y = 小列表[1]
    ActionChains(浏览器对象).move_to_element_with_offset(验证码图片,x,y).click().perform()
time.sleep(5)
浏览器对象.find_element_by_id("J-login").click()
