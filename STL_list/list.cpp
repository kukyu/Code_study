// 构造函数 赋值和交换 大小操作 插入和删除与之前容器一样
// 不可以用[]和at()访问list容器 ,只能访问头尾，不支持随机访问 支持i++，i--
// * `front();`        //返回第一个元素。
// * `back();`         //返回最后一个元素。
// * 尾插   --- push_back
// * 尾删   --- pop_back
// * 头插   --- push_front
// * 头删   --- pop_front
// * 插入   --- insert
// * 删除   --- erase
// * 移除   --- remove
// * 清空   --- clear

#include<iostream>
using namespace std;

#include <list>

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//插入和删除
void test01()
{
	list<int> L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	printList(L);

	//尾删
	L.pop_back();
	printList(L);

	//头删
	L.pop_front();
	printList(L);

	//插入
	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);

	//删除
	it = L.begin();
	L.erase(++it);
	printList(L);

	//移除
	L.push_back(10000);
	L.push_back(10000);
	L.push_back(10000);
	printList(L);
	L.remove(10000);  //删除所有一样的值
	printList(L);
    
    //清空
	L.clear();
	printList(L);
}

int main() {

	test01();

	system("pause");

	return 0;
}