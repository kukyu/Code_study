// #include<iostream>
// using namespace std;

// // 对象的初始化和清理
// // 1.构造函数 进行初始化操作

// class Person
// {
// public:
//     // 1.构造函数
//     // 没有返回值 不用写void
//     // 函数与类名相同
//     // 构造函数可以有参数 可以发生重载
//     // 创建对象的时候 函数自动调用，而且只调用一次
//     Person()
//     {
//         cout << "Person构造函数的引用" << endl;
//     }
//     // 2.析构函数 进行清理的操作
//     // 没有返回值 不用void
//     // 函数名和类型名相同 在名称前加~
//     // 函数名不可以有参数 不可以重载
//     // 对象销毁前 会自动调用 而且智慧调用一次
//     ~Person()
//     {
//         cout << "Person 的析构函数调用" << endl;
//     }
// };
// // 构造和析构函数都是必须有的实现，如果我们不提供，编译器会提供一个空实现的构造析构函数
// void test01()
// {
//     Person P; //在在栈上的数据，test01执行完毕释放这个对象
// }

// int main()
// {
//     // test01();
//     Person p;
//     system("pause");
// }

// #include <iostream>
// using namespace std;

// // 1.构造函数分类及调用
// // 分类
// class Person
// {
// public:
//     // 普通构造函数
//     Person()
//     {
//         cout << "这是无参构造函数调用" << endl;
//     }
//     Person(int a)
//     {
//         age = a;
//         cout << "这是有参构造函数调用" << endl;
//     }
//     // 拷贝构造函数
//     Person(const Person &p)
//     {
//         // 将传入的人身上的所有属性,拷贝到我身上
//         age = p.age;
//         cout << "这是拷贝构造函数调用" << endl;
//     }

//     // 析构函数
//     ~Person()
//     {
//         cout << "这是析构函数" << endl;
//     }
//     int age;
// };
// // 调用
// void test01()
// {
//     // // 1.括号法
//     // // 注意事项1 调用默认构造函数时,不要加(),会被编译器认为是函数的声明Person p1();
//     // Person p1;     //默认函数构造
//     // Person p2(10); // 有参构造函数
//     // Person p3(p2); // 拷贝构造函数
//     // 2.显示法
//     Person p1;
//     Person p2 = Person(10); // 有参构造
//     Person p3 = Person(p3); // 拷贝构造
//     // Person(10); //匿名对象 特点:当前行执行结束后,系统会自动回收匿名对象
//     // cout << "aaa" << endl;
//     // 注意事项2 不要利用拷贝构造函数初始化匿名对象 编译器会认为 Person(p3) === Person(p3) 对象声明
//     // 3.隐式转换法
//     Person p4 = 10; // 相当于写了 Person p4 = Person(10);
//     Person p5 = p4; // 拷贝构造
// }

// int main()
// {
//     test01();
//     system("pause");
// }