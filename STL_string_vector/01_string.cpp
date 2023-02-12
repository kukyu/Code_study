#include <iostream>
using namespace std;

#include <string>
// string构造
void test01()
{
    string s1; // 创建空字符串，调用无参构造函数
    // cout << "str1 = " << s1 << endl;

    const char *str = "hello world";
    string s2(str); // 把c_string转换成了string

    cout << "str2 = " << s2 << endl;

    string s3(s2); // 使用一个string对象初始化另一个string对象
    cout << "str3 = " << s3 << endl;

    string s4(10, 'a'); // 使用n个字符c初始化
    cout << "str3 = " << s4 << endl;
}

int main()
{

    test01();

    // system("pause");

    return 0;
}