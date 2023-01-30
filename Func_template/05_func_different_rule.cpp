#include <iostream>
using namespace std;
// 普通函数与函数模板调用规则
// 1.都可以调用，优先普通函数
// 2.可以通过空模板参数列表 强制调用函数模板
// 3.函数模板可以发生重载
// 4.如果函数模板可以产生更好的匹配，优先调用函数模板

void MyPrint(int a, int b)
{
    cout << "调用普通函数" << endl;
}

template <typename T>
void MyPrint(T a, T b)
{
     cout << "调用函数模板" << endl;
}

void test01()
{
    int a = 10;
    int b = 20;
    // MyPrint(a, b);

    //通过空模板参数列表强制调用
    // MyPrint<>(a, b);

    //更好的匹配，优先调用
    char c1 = 'a';
    char c2 = 'b';
    MyPrint(c1, c2);
}
int main()
{
    test01();
    return 0;
}