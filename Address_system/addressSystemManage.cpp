#include <iostream>
using namespace std;
#include <string>

#define MAX 1000
// 设计联系人的结构体
struct Person
{
    // 姓名
    string m_Name;
    // 性别 1 男 2 女
    int m_Sex;
    // 年龄
    int m_Age;
    // 电话
    string m_Phone;
    // 住址
    string m_addr;
};
// 设计通讯录结构体
struct Addressbooks
{
    //  通讯录保存的联系人数组
    struct Person personArray[MAX];
    // 通讯录当前记录的人数
    int m_Size;
};
//显示菜单界面
void showMenu()
{
    cout << "************************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "************************" << endl;
}
// 1.添加联系人
void addPerson(Addressbooks *abs)
{
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
    }
    else
    {
        // 添加具体联系人
        //姓名
        string name;
        cout << "请输入姓名:" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        //性别
        cout << "请输入性别:" << endl;
        cout << "1--男" << endl;
        cout << "2--女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            // 如果输入正确值可以退出
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误,请重新输入" << endl;
        }
        //年龄
        int age = 0;
        cout << "请输入年龄:" << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //电话
        cout << "请输入电话:" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;
        // 住址
        cout << "请输入家庭地址:" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_addr = address;
        // 更新通讯录联系人
        abs->m_Size++;
        cout << "添加成功" << endl;
        system("pause"); //请按任意键
        system("cls");   //清屏操作
    }
}

// 2.显示联系人
void showPerson(Addressbooks *abs)
{
    // 判断是否为空
    if (abs->m_Size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名:" << abs->personArray[i].m_Name << "\t";
            cout << "性别:" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄:" << abs->personArray[i].m_Age << "\t";
            cout << "电话:" << abs->personArray[i].m_Phone << "\t";
            cout << "地址:" << abs->personArray[i].m_addr << endl;
        }
    }
    system("pause");
    system("cls");
}
// 检测联系人是否存在 存在返回下标 不存在返回-1
int isExist(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}
// 3.删除指定联系人
void deletePerson(Addressbooks *abs)
{
    cout << "请删除您要删除的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            //数据前移操作
            abs->personArray[i] = abs->personArray[i + 1];
            abs->m_Size--; //更新通讯录人员数
            cout << "删除成功" << endl;
        }
    }
    else
    {
        cout << "查无此人,请重新输入。" << endl;
    }
    system("pause");
    system("cls");
}
// 4.查找联系人
void findPerson(Addressbooks *abs)
{
    cout << "请输入您要查找的联系人:" << endl;
    string name;
    cin >> name;
    // 判断是否在通讯录中
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名:" << abs->personArray[ret].m_Name << "\t";
        cout << "性别:" << abs->personArray[ret].m_Sex << "\t";
        cout << "年龄:" << abs->personArray[ret].m_Age << "\t";
        cout << "电话:" << abs->personArray[ret].m_Phone << "\t";
        cout << "地址:" << abs->personArray[ret].m_addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}
// 5.修改指定联系人信息
void modifyPerson(Addressbooks *abs)
{
    cout << "请输入您要修改的联系人:" << endl;
    string name;
    cin >> name;
    // 判断是否在通讯录中
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        //姓名
        string name;
        cout << "请输入姓名:" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        //性别
        int sex = 0;
        cout << "请输入性别:" << endl;
        cout << "1--男" << endl;
        cout << "2--女" << endl;
        while (true)
        {
            cin >> sex;
            // 如果输入正确值可以退出
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "输入有误,请重新输入" << endl;
        }
        //年龄
        int age = 0;
        cout << "请输入年龄:" << endl;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        //电话
        cout << "请输入电话:" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;
        // 住址
        cout << "请输入家庭地址:" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_addr = address;
        // 更新通讯录联系人
        cout << "修改成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause"); //请按任意键
    system("cls");   //清屏操作
}
// 6.清空联系人
void cleanPerson(Addressbooks *abs)
{
    cout << "请再次确定:清空按1 取消按2" << endl;
    int input;
    cin >> input;
    if (input == 1)
    {
        abs->m_Size = 0; // 当期联系人数量置于0,逻辑清空
        cout << "通讯录已清空" << endl;
    }
    else
    {
        return;
    }
    system("pause"); //请按任意键
    system("cls");   //清屏操作
}
int main()
{
    // 创建通讯录结构体变量
    Addressbooks abs;
    // 初始化通讯录当前人员个数
    abs.m_Size = 0;
    int select = 0; //创建用户选择输入的变量
    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:              // 1.添加联系人
            addPerson(&abs); // 地址传递
            break;
        case 2: // 2.显示联系人
            showPerson(&abs);
            break;
        case 3: // 3.删除联系人
            deletePerson(&abs);
            break;
        case 4: // 4.查找联系人
            findPerson(&abs);
            break;
        case 5: // 5.修改联系人
            modifyPerson(&abs);
            break;
        case 6: // 6.清空联系人
            cleanPerson(&abs);
            break;
        case 0: // 0.退出通讯录
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}