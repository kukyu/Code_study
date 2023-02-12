#include <iostream>
using namespace std;
#include <string>
// 字符串比较
void test01()
{

    string s1 = "hello";
    string s2 = "aello";
    // 字符串比较是按字符的ASCII码进行对比
    int ret = s1.compare(s2);

    if (ret == 0)
    {
        cout << "s1 等于 s2" << endl;
    }
    else if (ret > 0)
    {
        cout << "s1 大于 s2" << endl;
    }
    else
    {
        cout << "s1 小于 s2" << endl;
    }
}

int main()
{

    test01();

    // system("pause");

    return 0;
}