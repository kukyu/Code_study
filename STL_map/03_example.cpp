#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
#include <ctime>
/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
*/

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
    // Worker(string name, int salary)
    // {
    //     this->mName = name;
    //     this->mSalary = salary;
    // }

    string mName;
    int mSalary;
};
void CreatWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.mName = "员工";
        worker.mName += nameSeed[i];
        worker.mSalary = rand() % 10001 + 10000;
        v.push_back(worker);
    }
}
void SetGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 产生随机部门编号
        int deptId = rand() % 3; // 0, 1, 2

        // 插入map中
        m.insert(make_pair(deptId, *it));
    }
}
void ShowWorkerByGroup(multimap<int, Worker> &m)
{
    cout << "策划部门:" << endl;
    // m.find(CEHUA);
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA); // 统计人数
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名:" << pos->second.mName << " "
             << "工资: " << pos->second.mSalary << endl;
    }
    cout << "---------------------" << endl;
    cout << "美术部门: " << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU); // 统计人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名:" << pos->second.mName << " "
             << "工资: " << pos->second.mSalary << endl;
    }
    cout << "---------------------" << endl;
    cout << "研发部门: " << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA); // 统计人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名:" << pos->second.mName << " "
             << "工资: " << pos->second.mSalary << endl;
    }
    cout << "---------------------" << endl;
}
int main()
{
    srand((unsigned int)time(NULL));
    // 1.创建员工
    vector<Worker> vWorker;
    CreatWorker(vWorker);
    // // 2.测试
    // for(vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
    // {
    //     cout << "姓名:" << it->mName << " " << "工资:" << it -> mSalary << endl;
    // }
    // 2.员工分组
    multimap<int, Worker> mWorker;
    SetGroup(vWorker, mWorker);
    // 3.显示员工

    ShowWorkerByGroup(mWorker);
    return 0;
}