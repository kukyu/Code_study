#include <iostream>
using namespace std;
#include <string>

// 子串
void test01()
{

    string str = "abcdefg";
    string subStr = str.substr(1, 3); // 从哪开始截，截几个
    cout << "subStr = " << subStr << endl;

    string email = "hello@sina.com";
    int pos = email.find("@");
    cout << pos << endl;
    string username = email.substr(0, pos);
    cout << "username: " << username << endl;
}

int main()
{

    test01();

    system("pause");

    return 0;
}