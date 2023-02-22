#include <iostream>
using namespace std;
#include <deque>

// **功能描述：**

// * 对deque中的数据的存取操作

// **函数原型：**

// * `at(int idx); `     //返回索引idx所指的数据
// * `operator[]; `       //返回索引idx所指的数据
// * `front(); `            //返回容器中第一个数据元素
// * `back();`              //返回容器中最后一个数据元素

void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }

    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1.at(i) << " ";
    }
    cout << endl;

    cout << "d1的第一个元素为： " << d1.front() << endl;
    cout << "d1的最后一个元素为： " << d1.back() << endl;
}

int main()
{

    test01();

    // system("pause");

    return 0;
}