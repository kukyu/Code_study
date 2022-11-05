// #include <iostream>
// using namespace std;

// int main()
// {
//     // 引用基本语法 &别名 = 原名
//     int a = 10;  //引用必须初始化，一旦初始化就不能更改
//     // 创建引用
//     int &b = a;
//     cout << "a=" << a << endl;
//     cout << "b=" << b << endl;
//     // 一旦初始化就不能更改
//     int c = 20;
//     b = c; // 赋值操作而不是更改引用
//     cout << "a=" << a << endl;
//     cout << "b=" << b << endl;
//     cout << "c=" << c << endl;

//     b = 100;
//     cout << "a=" << a << endl;
//     cout << "b=" << b << endl;
//     return 0;
// }
// #include <iostream>
// using namespace std;

// // 1.值传递
// void mySwap01(int a, int b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// // 2.地址传递
// void mySwap02(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // 3.引用传递
// void mySwap03(int &a, int &b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// int main()
// {
//     int a = 10;
//     int b = 20;
//     // mySwap01(a, b); //值传递
//     // mySwap02(&a, &b); // 地址传递 形参修饰实参
//     mySwap03(a, b);  // 引用传递 形参修饰实参
//     cout << "01a=" << a << endl;
//     cout << "01b=" << b << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// // 1.值传递
// void mySwap01(int a, int b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// // 2.地址传递
// void mySwap02(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // 3.引用传递
// void mySwap03(int &a, int &b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// int main()
// {
//     int a = 10;
//     int b = 20;
//     // mySwap01(a, b); //值传递
//     // mySwap02(&a, &b); // 地址传递 形参修饰实参
//     mySwap03(a, b);  // 引用传递 形参修饰实参
//     cout << "01a=" << a << endl;
//     cout << "01b=" << b << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
void showValue(const int &val)
{
    // val = 1000; // 加入const 不能修改数据
    cout << "val = " << val << endl;
}
int main()
{
    //常量引用
    // 用来修饰形参 防止误操作
    // 加上const之后 编译器将代码修改 int temp = 10; const int &ref = temp;
    // int a = 10;
    // int &ref = 10; //不合法
    // const int &ref = 10; //引用必须引一块合法的内存空间
    // ref  = 10; //加入const后只读 不可修改
    int a =100;
    showValue(a);
    cout << "a=" << a << endl; //  引用a的值被改变
}
