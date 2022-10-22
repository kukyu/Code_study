
// //描述一个学生 需要性别 年龄 电话 性别
// // struct 结构体关键字； Stu 结构体标签；struct Stu 结构体类型
// struct Stu
// {   // 成员变量
//     char name[20];
//     short age;
//     char tele[12];
//     char sex[5];
// }s1,s2 ,s3; //s1,s2,s3 是三个全局变量（不建议）
// int main
// {
//     struct Stu s; //创建结构体变量 局部变量

//     return 0;
// }
// # include <stdio.h>
// //描述一个学生 需要性别 年龄 电话 性别
// // struct 结构体关键字； Stu 结构体标签；struct Stu 结构体类型
// // 对类型进行重命名
// typedef struct Stu
// { // 成员变量
//     char name[20];
//     short age;
//     char tele[12];
//     char sex[5];
// } Stu; //重新取名叫Stu Stu是类型
// int main()
// {
//     Stu s1= {"张三", 20, "13276456666", "保密"}; //结构体初始化
//     return 0;
// }

// # include <stdio.h>
// // 结构体的嵌套引用
// struct S
// { // 成员变量
//     int a;
//     char c;
//     char arr[20];
//     double d;

// } ;
// struct T
// {
//     char ch[10];
//     struct S s;
//     char *p;

// };
// int main()
// {
//     char arr[]="hello bit\n";
//     struct T t = {"heheh", {100, 'w', "hello world", 3.14}, arr};//初始化
//     printf("%s\n", t.ch);
//     printf("%s\n",t.s.arr);
//     return 0;
// }

#include <stdio.h>
typedef struct Stu
{ // 成员变量
    char name[20];
    short age;
    char tele[12];
    char sex[5];
} Stu; //重新取名叫Stu Stu是类型

void print1(Stu temp)
{
    printf("name:%s\n", temp.name);
    printf("age:%d\n", temp.age);
    printf("Tel:%s\n", temp.tele);
}
void print2(Stu *temp)
{
    printf("name:%s\n", temp->name);
    printf("age:%d\n", temp->age);
    printf("Tel:%s\n", temp->tele);
}
int main()
{
    Stu s = {"张三", 16, "12344555", "男"};
    print1(s);
    print2(&s);
    return 0;
}