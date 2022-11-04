//

// // 不要返回局部变量地址
// #include <iostream>
// using namespace std;

// int * func(int b)
// {
//     int a = 10; // 局部变量
//     return &a; // 返回局部变量地址
// }

// int main()
// {
//     // 接收func函数的返回值
//     int *p = func(1);
//     cout << *p << endl;
//     system("pause");
//     return 0;
// }
// #include <iostream>
// using namespace std;

// int *func()
// {
//     //利用new关键字 可以将数据开辟到堆区
    
//     int *p = new int(10);
//     return p;  
// }

// int main()
// {
//     //在堆区开辟数据
//     int *p = func();
//     cout << *p << endl;


//     system("pause");
//     return 0;
// }


#include <iostream>
using namespace std;

int *func()
{
    //利用new关键字 可以将数据开辟到堆区
    // new 返回是 该数据类型的指针
    int *p = new int(10);
    return p;  
}

void test()
{
    // 创建10整型数据的数组
    int *arr = new int[10]; //数组有十个元素
    delete [] arr; //释放数组要加[]
}
int main()
{
    //在堆区开辟数据
    int *p = func();
    cout << *p << endl;
    //释放内存
    // delete p;


    system("pause");
    return 0;
}