// #include <iostream>
// using namespace std;
// double Pi = 3.1415926;
// // 设计一个圆类，求圆的周长

// // class设计一个类
// class Circle
// {
//     // 访问权限
//     // 公共权限
// public:
//     //属性
//     // 半径
//     int m_r;
//     // 行为
//     // 获取圆的周长
//     double calculateZC()
//     {
//         return 2 * Pi * m_r;
//     }
// };

// int main()
// {
//     // 通过圆类 创建具体的圆
//     // 实例化
//     Circle c1;
//     // 给圆属性赋值
//     c1.m_r = 10;
//     cout << "圆的周长为：" << c1.calculateZC() << endl;
// }

// #include <iostream>
// using namespace std;
// #include <string>
// // class设计一个类
// class Student
// {
//     // 访问权限
//     // 公共权限
// public:
//     // 类中的属性和行为 我们统一称为成员
//     //属性  成员属性 成员变量
//     // 行为 成员函数 成员方法

//     // 属性
//     // 姓名 学号
//     string m_Name;
//     int m_id;
//     // 行为
//     // 显示姓名与学号
//     void showStudent()
//     {
//         cout << "姓名：" << m_Name << "学号：" << m_id << endl;
//     }
//     // 给姓名赋值
//     void setName(string name)
//     {
//         m_Name = name;
//     }
// };

// int main()
// {
//     // 实例化
//     Student s1;
//     s1.setName("张三");
//     s1.m_id = 12357;
//     s1.showStudent();
// }

// 03 封装权限控制
// #include <iostream>
// using namespace std;
// #include <string>
// // class设计一个类
// class Person
// {
//     // 访问权限
//     // 公共权限
// public:
//     // 公共权限
//     string m_Name;

// protected:
//     // 保护权限
//     string m_Car;

// private:
//     // 私有权限
//     int m_Password;

// public:
//     void fun()
//     {
//         m_Name = "张三";
//         m_Car = "拖拉机";
//         m_Password = 123456; // 类内可以访问
//     }
// };
// int main()
//     {
//         // 实例化
//         Person p1;
//         p1.m_Name = "张三";
//         // p1.m_Car = "拖拉机"; //保护权限内容 类外访问不到
//         // p1.m_Password = 123456; //私有权限内容 类外访问不到
//     }
// struct 和 class区别
// struct 默认权限是公共权限 public
// class 默认权限是私有 private
// #include <iostream>
// using namespace std;
// #include <string>
// // class设计一个类
// class C1
// {
//     int m_A; // 默认权限 是私有
// };

// struct C2
// {
//     int m_A; // 默认权限是公共
// };
// int main()
//     {
//         // 实例化
//         C1 c1;
//         c1.m_A = 100; //私有不可访问
//         C2 c2;
//         c2.m_A = 100; // struct 可以访问
//     }

// //  成员属性设置为私有
// //  自己控制读写的权限
// //  对于写可以检测数据的有效性
// #include <iostream>
// using namespace std;
// #include <string>
// // class设计一个类
// class Person
// {
// public:
//     // 设置姓名
//     void setName(string name)
//     {
//         m_Name = name;
//     }
//     // 获取姓名
//     string getName()
//     {
//          return m_Name;
//     }
//     // 获取年龄
//     int getAgg()
//     {
//         m_age = 0; //只读 初始化年龄
//         return m_age;
//     }
//     // 设置情人 只写
//     void setLover(string lover)
//     {
//         m_lover = lover;
//     }
//     // 设置年龄检测
//     void set_Age(int age)
//     {
//         if(age < 0 || age > 150)
//         {
//             cout << "输入年龄不对，请检查输入" << endl;
//             return;
//         }
//         m_age = age;
//     }
// private:
//     // 姓名
//     string m_Name; //可读可写
//     // 年龄
//     int m_age; // 只读
//     // 情人
//     string m_lover; // 只写
// };

// int main()
//     {
//         // 实例化
//         Person p;
//         p.setName("张三");
//         cout << "姓名为：" <<  p.getName() << endl;
//         cout << "年龄为:" << p.getAgg() << endl;
//         // p.m_age = 18; // 只读不可修改
//         p.setLover("Lucy");
//         // cout << "情人为" << p.setLover <<endl; // 只写 不可以访问
//         p.set_Age(1000);
//         return 0;
//     }

// // 练习案例1
// // 设置立方体类
// // 求出立方体的面积和体积
// // 分别用全局函数和成员函数判断两个立方体是否相等
// #include <iostream>
// using namespace std;
// #include <string>
// // 设置立方体类
// class Cube
// {
//     // 设置公共属性 从私有中拿出
// public:
//     // 设置长宽高
//     void setLong(int chang)
//     {
//         m_Long = chang;
//     }
//     void setWidth(int width)
//     {
//         m_Width = width;
//     }
//     void setHigth(int higth)
//     {
//         m_Higth = higth;
//     }
//     // 获取长宽高
//     int getLong()
//     {
//         return m_Long;
//     }
//     int getWidth()
//     {
//         return m_Width;
//     }
//     int getHigth()
//     {
//         return m_Higth;
//     }
//     //行为 获取面积与体积
//     int calS()
//     {
//         return 2 * m_Long * m_Width + 2 * m_Long * m_Higth + 2 * m_Width * m_Higth;
//     }
//     int calV()
//     {
//         return m_Higth * m_Long * m_Width;
//     }
//      // 利用成员函数判断相等
//     bool isSameByClass(Cube &c)
//     {
//         if (m_Long == c.getLong() && m_Width == c.getWidth() && m_Higth == c.getHigth())
//     {
//         return true;
//     }
//     return false;
//     }
// private:
//     //属性
//     // 长宽高
//     int m_Long;
//     int m_Width;
//     int m_Higth;
// };
// // 利用全局函数判断相等
// bool isSame(Cube &c1, Cube &c2)
// {
//     if (c1.getLong() == c2.getLong() && c1.getWidth() == c2.getWidth() && c1.getHigth() == c2.getHigth())
//     {
//         return true;
//     }
//     return false;
// }
// int main()
// {
//     // 实例化
//     Cube c1;
//     c1.setLong(10);
//     c1.setWidth(10);
//     c1.setHigth(10);
//     cout << "面积：" << c1.calS() << endl
//          << "体积：" << c1.calV() << endl;

//     Cube c2;
//     c2.setLong(10);
//     c2.setWidth(90);
//     c2.setHigth(10);
//     cout << "面积：" << c2.calS() << endl
//          << "体积：" << c2.calV() << endl;
//     // 利用全局函数判断相等
//     bool ret = isSame(c1, c2);
//     if(ret)
//     {
//         cout << "c1和c2相等。" << endl;
//     }
//     else
//     {
//         cout << "c1和c2不相等。" << endl;
//     }

//     //  利用成员函数判断相等
//     bool ret2 = c1.isSameByClass(c2);
//     if(ret2)
//     {
//         cout << "成员函数判断" << endl;
//         cout << "c1和c2相等。" << endl;
//     }
//     else
//     {   cout << "成员函数判断" << endl;
//         cout << "c1和c2不相等。" << endl;
//     }

//     return 0;
// }

//  练习案例2
// 点和圆关系的案例
// 圆类
// #include <iostream>
// using namespace std;
// #include <string>
// // // 点类
// // class Point
// // {
// // public:
// //     //设置x
// //     void setX(int x)
// //     {
// //         m_X = x;
// //     }
// //     // 设置y
// //     void setY(int y)
// //     {
// //         m_Y = y;
// //     }
// //     //获取x
// //     int getX()
// //     {
// //         return m_X;
// //     }
// //     //获取y
// //     int getY()
// //     {
// //         return m_Y;
// //     }

// // private:
// //     int m_X;
// //     int m_Y;
// // };
// // 设置圆类
// class Circle
// {
//     // 设置公共属性 从私有中拿出
// public:
//     // 设置半径
//     void setR(int r)
//     {
//         m_R = r;
//     }
//     // 获取半径
//     int getR()
//     {
//         return m_R;
//     }
//     // 设置圆心
//     void setCenter(Point center)
//     {
//         m_Center = center;
//     }
//     // 获取圆心
//     Point getCenter()
//     {
//         return m_Center;
//     }

// private:
//     //属性
//     // 半径
//     int m_R;
//     // 圆心
//     Point m_Center;
// };
// 判断点和圆之间的关系
// 计算两点之间距离的平方 半径的平方
// void isInCircle(Circle &c, Point &p)
// {
//     //计算两点之间距离的平方
//     int distance = (c.getCenter().getX() - p.getX()) ^ 2 + (c.getCenter().getY() - p.getY()) ^ 2;
//     // 计算半径的平方
//     int rDistance = c.getR() ^ 2;
//     if (distance == rDistance)
//     {
//         cout << "点在圆上" << endl;
//     }
//     else if (distance > rDistance)
//     {
//         cout << "点在圆外" << endl;
//     }
//     else
//     {
//         cout << "点在圆内" << endl;
//     }
// }
// int main()
// {
//     //实例化
//     //创建一个圆
//     Circle c1;
//     c1.setR(10);
//     Point p1;
//     p1.setX(0);
//     p1.setY(0);
//     c1.setCenter(p1);
//     //创建一个点
//     Point p2;
//     p2.setX(0);
//     p2.setY(10);
//     //判断关系
//     isInCircle(c1, p2);
//     return 0;
// }