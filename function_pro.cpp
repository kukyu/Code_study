// #include <iostream>
// using namespace std;

// int func(int a, int b = 20, int c = 30) // 如果自己传入数据，就用自己的数据，如果没有，就用默认值
// {
//     return a + b + c;
// }

// int func2(int a, int b = 10, int c = 10, int d = 20); //声明有默认参数 函数实现不能有默认参数

// int main()
// {
//     cout << func(10, 30) << endl;
//     cout << func2(2) << endl;
//     // system("pause");
//     return 0;
// }
// int func2(int a, int b, int c, int d) //前面有参数赋值后面必须赋值
// {
//     return a + b + c + d;
// }

// #include <iostream>
// using namespace std;

// // 占位参数
// void func(int a, int) //现在占位参数还用不到
// // void func(int a, int = 10) //默认参数
// {
//     cout << "this is function " << endl;
// }

// int main()
// {
//     func(10, 10);
//     return 0;
// }

// #include <iostream>
// using namespace std;

// //函数重载
// // 满足条件：
// // 1.同一个作用域
// // 2.函数名称相同
// // 3.函数名类型不同 或者 个数不同 或者 顺序不同
// void func()
// {
//     cout << "func的调用 " << endl;
// }

// void func(int a) //个数不同
// {
//     cout << "func的调用2 " << endl;
// }

// void func(double a, int b) //类型不同
// {
//     cout << "func的调用3 " << endl;
// }
// void func(int b, double a) //顺序不同
// {
//     cout << "func的调用4 " << endl;
// }

// int main()
// {
//     func(2.1,3);
//     return 0;
// }

#include <iostream>
using namespace std;
// 函数重载的注意事项
// 引用作为函数重载的条件
void func(int &a)
{
    cout << "func的调用1 " << endl;
}

void func(const int &a)
{
    cout << "func的调用2 " << endl;
}
// 函数重载碰到默认参数
void func2(int a, int b=10) //函数重载碰到默认参数，出现二义性
{
    cout << "func的调用3 " << endl;
}
void func2(int a)
{
    cout << "func的调用4 " << endl;
}

int main()
{
    // int a = 10;
    // func(a);
    func(10); // int &a =10; 不合法 走const
    // func2(10);// 二义性
    return 0;
}
