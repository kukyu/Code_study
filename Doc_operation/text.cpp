// #include<iostream>
// using namespace std;
// # include <fstream> // 头文件包含
//  // 文本文件 写文件

//  void test01()
//  {
//     // 1.包含头文件 fstream
//     // 2.创建流对象
//     ofstream ofs;
//     // 3.指定打开方式
//     ofs.open("text.txt", ios::out);
//     // 4. 写内容
//     ofs << "姓名:张三" << endl;
//     ofs << "性别:男" << endl;
//     ofs << "年龄:18" << endl;
//     // 5.关闭文件
//     ofs.close();
//  }
// int main()
// {
//     test01();
//     return 0;
// }


// #include<iostream>
// using namespace std;
// # include <fstream> // 头文件包含
// #include<string>
//  // 文本文件 读文件

//  void test01()
//  {
//     // 1.包含头文件 fstream
//     // 2.创建流对象
//     ifstream ifs;
//     // 3.打开文件并判断文件是否打开成功
//     ifs.open("text.txt", ios::in);
//     if(!ifs.is_open())
//     {
//         cout << "文件打开失败" << endl;
//         return;
//     }
//     // 4. 读内容的四种方式
//     // // 4.1 
//     // char buf[1024] = {0};
//     // while(ifs >> buf)
//     // {
//     //     cout << buf << endl;
//     // }
//     // 4.2
//     // char buf[1024] = {0};
//     // while(ifs.getline(buf, sizeof(buf)))
//     // {
//     //     cout << buf << endl;
//     // }
//     // 4.3
//     // string buf;
//     // while(getline(ifs, buf))
//     // {
//     //     cout << buf << endl;
//     // }
//     // 4.4
//     // char c;
//     // while((c = ifs.get()) != EOF) // EOF end of file
//     // {
//     //     cout << c;
//     // }
//     // 5.关闭文件
//     ifs.close();
//  }
// int main()
// {
//     test01();
//     return 0;
// }


// #include<iostream>
// using namespace std;
// # include <fstream> // 头文件包含
//  // 文本文件 写二进制文件
// class Person
// {
// public:
//     char m_Name[64]; //姓名
//     int m_Age; // 年龄
// };
// void test01()
// {
// // 1.包含头文件 fstream
// // 2.创建流对象
// ofstream ofs("person.txt", ios::out | ios :: binary);
// // 3.指定打开方式
// // ofs.open("person.txt", ios::out | ios :: binary);
// // 4. 写内容
// Person p = {"张三", 18};
// ofs.write((const char *)&p, sizeof(Person));
// // 5.关闭文件
// ofs.close();
// }
// int main()
// {
// test01();
// return 0;
// }



#include<iostream>
using namespace std;
# include <fstream> // 头文件包含
#include<string>
 // 文本文件 读二进制文件

class Person
{
public:
    char m_Name[64];
    int m_Age;
};
 void test01()
 {
    // 1.包含头文件 fstream
    // 2.创建流对象
    ifstream ifs;
    // 3.打开文件并判断文件是否打开成功
    ifs.open("person.txt", ios::in | ios::binary);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    // 4. 读内容的四种方式
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "姓名:" << p.m_Name  << endl << "年龄:" << p.m_Age << endl;
    // 5.关闭文件
    ifs.close();
 }
int main()
{
    test01();
    return 0;
}
