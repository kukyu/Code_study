#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

void MyPrint(int val)
{
    cout << val << endl;
}
// vector容器存放内置数据类型
void test01()
{

    vector<int> v;

    // 向容器中插入数据 尾插法
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator itBegin = v.begin(); // 起始迭代器，指向第一个元素
    vector<int>::iterator itEnd = v.end();     // 结束迭代器，指向最后一个元素的下一个元素

    // 遍历1
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
    // 遍历2
    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
    {
        cout << *it << endl;
    }
    //遍历3算法 for_each
    for_each(v.begin(), v.end(), MyPrint);
}
int main()
{
    test01();
    return 0;
}