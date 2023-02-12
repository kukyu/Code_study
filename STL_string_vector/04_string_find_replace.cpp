#include <iostream>
using namespace std;
#include <string>

// 查找和替换
void test01()
{
    // 查找
    string str1 = "abcdefgde";

    int pos = str1.find("de");  //查找第一个索引位置

    if (pos == -1)
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl;
    }

    pos = str1.rfind("de");  //查找最后一个索引位置

    cout << "pos = " << pos << endl;
}

void test02()
{
    // 替换
    string str1 = "abcdefgde";
    str1.replace(1, 3, "1111111111"); // 替换1-3位置

    cout << "str1 = " << str1 << endl;
}

int main()
{

    test01();
    test02();

    // system("pause");

    return 0;
}