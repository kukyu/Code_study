#include <iostream>
using namespace std;
#include <deque>

void printVector(deque<int> &d)
{

    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d1; // 无参构造
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printVector(d1);

    deque<int> d2(d1.begin(), d1.end());
    printVector(d2);

    deque<int> d3(10, 100);
    printVector(d3);

    deque<int> d4(d3);
    printVector(d4);
}

int main()
{

    test01();

    // system("pause");

    return 0;
}