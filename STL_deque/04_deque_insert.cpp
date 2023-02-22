// **函数原型：**

// 两端插入操作：

// - `push_back(elem);`          //在容器尾部添加一个数据
// - `push_front(elem);`        //在容器头部插入一个数据
// - `pop_back();`                   //删除容器最后一个数据
// - `pop_front();`                 //删除容器第一个数据
// 指定位置操作：
// * `insert(pos,elem);`         //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
// * `insert(pos,n,elem);`     //在pos位置插入n个elem数据，无返回值。
// * `insert(pos,beg,end);`    //在pos位置插入[beg,end)区间的数据，无返回值。
// * `clear();`                           //清空容器的所有数据
// * `erase(beg,end);`             //删除[beg,end)区间的数据，返回下一个数据的位置。
// * `erase(pos);`                    //删除pos位置的数据，返回下一个数据的位置。

#include <iostream>
using namespace std;
#include <deque>

void printdeque(deque<int> &d)
{

	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// 插入和删除
void test01()
{
	deque<int> d1;
	// 尾插 append
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(40);
	d1.push_front(50);
	printdeque(d1);
	// 尾删  删除最后一个元素
	d1.pop_back();
	printdeque(d1);
	d1.pop_front();
	printdeque(d1);
	// 插入 插入第一个位置
	d1.insert(d1.begin(), 100);
	printdeque(d1);

	d1.insert(d1.begin(), 2, 1000); // 在开始插入两个元素
	printdeque(d1);
	d1.insert(d1.begin(), d1.begin(), d1.end()); // 按照区间进行插入
	printdeque(d1);
	// 删除  删除第一个元素
	d1.erase(d1.begin());
	printdeque(d1);

	// 清空
	d1.erase(d1.begin(), d1.end());
	d1.clear();
	printdeque(d1);
}

int main()
{

	test01();

	system("pause");

	return 0;
}