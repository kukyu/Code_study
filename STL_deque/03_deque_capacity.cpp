#include <iostream>
using namespace std;
#include <deque>

// **功能描述：**

// * 对deque容器的容量和大小操作

// **函数原型：**
// * `empty(); `                            //判断容器是否为空
// * `size();`                              //返回容器中元素的个数
// * `resize(int num);`             //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
//   ​					      //如果容器变短，则末尾超出容器长度的元素被删除。
// * `resize(int num, elem);`  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
//   ​				              //如果容器变短，则末尾超出容器长度的元素被删除
void printdeque(deque<int> &d)
{

    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);
    if (d1.empty())
    {
        cout << "d1为空" << endl;
    }
    else
    {
        cout << "d1不为空" << endl;
        // cout << "d1的容量 = " << d1.capacity() << endl; // deque没有容量大小限制
        cout << "d1的大小 = " << d1.size() << endl;
    }

    // resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
    d1.resize(15, 10);
    printdeque(d1);

    // resize 重新指定大小 ，若指定的更小，超出部分元素被删除
    d1.resize(5);
    printdeque(d1);
}

int main()
{

    test01();

    // system("pause");

    return 0;
}
