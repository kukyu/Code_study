// 大小和交换
// swap(),size(), empty()

//插入和删除
// * `insert(elem);`           //在容器中插入元素。
// * `clear();`                    //清除所有元素
// * `erase(pos);`              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
// * `erase(beg, end);`    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
// * `erase(elem);`            //删除容器中值为elem的元素。

	// //插入
	// map<int, int> m;
	// //第一种插入方式
	// m.insert(pair<int, int>(1, 10));
	// //第二种插入方式
	// m.insert(make_pair(2, 20));
	// //第三种插入方式
	// m.insert(map<int, int>::value_type(3, 30));
	// //第四种插入方式
    // m[4] = 40; 
// ####查找和统计
// - `find(key);`                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，
                                    // 返回.end();
// - `count(key);`                //统计key的元素个数


