#include <iostream>
using namespace std;
// 普通函数与函数模板区别
// 1.普通函数调用可以发生隐式类型转换
// 2.函数模板用自动类型推导，不可以发生隐式类型转换
// 3.函数模板用显示指定类型，可以发生隐式类型转换

// 普通函数
int Myadd01(int a, int b)
{
    return a + b;
}

//函数模板
template<typename T>
T MyAdd02(T a, T b)
{
    return a + b;
}
void test01()
{
    int a = 10; //97
    int b = 20;
    char c = 'c'; //99
    cout << Myadd01(a, c) << endl;
    cout << MyAdd02(a, b) << endl;
    // cout << MyAdd02(a, c) << endl; //自动类型推导错误
    cout << MyAdd02<int>(a, c) << endl; //显示指定类型
}


int main()
{
    test01();
    // system("pause");
    return 0;
}
