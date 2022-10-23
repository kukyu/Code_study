// #include <stdio.h>
// int main()
// {
//     int a = 0x11223344;
//     int *pa = &a;
//     char *pc = &a;
//     printf("%p\n", pa);
//     printf("%p\n", pa + 1);

//     printf("%p\n", pc);
//     printf("%p\n", pc + 1);
// }

// # include <stdio.h>
// int main()
// {
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     int *p = arr;
//     int i = 0;
//     for(i=0;i<5;i++)
//     {
//         printf("%d", *p);
//         p+=2;
//     }
//     return 0;
// }
// # include <stdio.h>
// int main()
// {
//    int arr[10]={8,2,3,4,5,6,7,8,9,20};
//    printf("%d\n",&arr[9]-&arr[0]);
// return 0;
// }

// #include <stdio.h>
// int my_strlen(char *str)
// {
//     char *start = str;
//     char *end = str;
//     while (*end != '\0')
//     {
//         end++;
//     }
//     return end - start;
// }
// int main()
// {
//     char arr[] = "bit";
//     int len = my_strlen(arr);
//     printf("%d\n", len);
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     int arr[10] = {0};
//     printf("%p\n", arr);
//     printf("%p\n", arr + 1);
//     printf("%p\n", &arr[0]);
//     printf("%p\n", &arr[0] + 1);
//     printf("%p\n", &arr); // 整个数组的地址即4X10=40
//     printf("%p\n", &arr + 1);
//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//    int a = 10;
//    int *pa =&a;
//    int **ppa = &pa;//ppa即二级指针
//    printf("%d\n", **ppa);
//    return 0;  //ans = 10
// }

//指针数组

// #include <stdio.h>
// int main()
// {
//    int a = 10;
//    int b = 20;
//    int c = 30;
//    int *arr[3] = {&a, &b, &c}; //指针数组
//    int i = 0;
//    for(i=0;i<3;i++)
//    {
//     printf("%d\t", *arr[i]);
//    }
//    return 0;

// }

// # include <stdio.h>
// void test(int arr[])
// {
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    printf("%d\n", sz);

// }
// int main()
// {
//    int arr[10] = {0};
//    test(arr);
//    return 0;
// }

// # include <stdio.h>
// int main()
// {
//   char arr[]="abcdef";
//   char *pc = arr;
//   printf("%s\n", arr);
//   printf("%s\n",*pc);
//   return 0;

// }

//  # include <stdio.h>
//  int main()
//  {
//    int arr1[]={1,2,3,4,5};
//    int arr2[]={2,2,3,4,5};
//    int arr3[]={3,2,3,4,5};
//    int* parr[] = {arr1,arr2, arr3};
//    int i = 0;
//    int j=0;
//    for(i=0;i<3;i++)
//    {
//       for(j=0;j<5;j++)
//       {
//          printf("%d",*(parr[i] +j));
//       }
//       printf("\n");
//    }
//    return 0;
//  }

// # include <stdio.h>
//  int main()
//  {
//    int arr2[]={1,2,3,4,5,6,7, 8, 9,10};
//    int (*pa)[10]=&arr2;
//    int i = 0;
//    for(i=0;i<10;i++)
//    {
//       printf("%d", (*pa)[i]);

//    }
//    return 0;
//  }

// # include <stdio.h>
// int main()
// {
//   int arr2[]={1,2,3,4,5,6,7, 8, 9,10};
//   int *p = arr2;
//   int i = 0;
//   for(i=0;i<10;i++)
//   {
//      printf("%d", *(p+i));
//      printf("%d",*(arr2+i));
//      printf("%d",arr2[i]);
//      printf("%d",p[i]); //*(p+i)==*(arr2+i)==arr2[i]==p[i]
//   }
//   return 0;
// }

//

// # include <stdio.h>
// void printf1(int (*p)[5],int x,int y)//void 代表不返回
// {
//    int i=0;
//    int j=0;
//    for(i=0;i<x;i++)
//    {
//       for(j=0;j<y;j++)
//       {
//          printf("%d\t",*(*(p+i)+j));
//          // printf("%d\t",(*(p+i))[j]);
//       }
//       printf("\n");
//    }

// }
// int main()
// {
//   int arr[3][5]={{1,2,3,4,5},{6,7, 8, 9,10},{2,3,4,5,6}};
//   printf1(arr,3,5);//定义一个函数
//   return 0;
// }

// # include <stdio.h>
// void test(int arr[])
// {}
// // void test(int arr[10])
// // {}
// // void test(int *arr)
// // {}
// // void test2(int *arr2[20])
// // {}
// // void test2(int **arr2)
// {}
// int main()
// {
//   int arr[10]={0};
//   int *arr2[20] = {0};
//   test(arr);
//   // test2(arr2);
// }
// # include <stdio.h>
// void test(int arr[3][5])
// {}
// void test(int arr[3][]) //写法错误 不能省略列，也不能省略所有
// {}
// void test(int arr[][5])
// {}
// void test1(int *arr) //二维数组首地址是第一行数组的地址，不能存放int整型中
// {}
// void test1(int *(arr)[5]) //数组指针 指针指向五个元素的一维数组的地址
// {}
// int main()
// {
//   int arr[3][5]={0};
//   test(arr);
//   test1(arr);
// }

// # include <stdio.h>
// void test(int *p)
// {}
// int main()
// {
//   int a=10;
//   int *p = &a;
//   test(&a);//ok
//   test(p); // ok
// }

// # include <stdio.h>
// void test(int **p)
// {
//   printf("%d",**p);
// }
// int main()
// {
//   int a=10;
//   int *p = &a;
//   int **pp =&p;
//   test(pp);//ok
//   test(&p); // ok
//   return 0;
// }

// #include <stdio.h>
// int Add(int x, int y)
// {
//   int z = 0;
//   z = x + y;
//   return z;
// }
// int main()
// {
//   int a = 10;
//   int b = 20;
//   printf("%d\n", Add(a, b));
//   printf("%p\n", &Add);
//   printf("%p\n", Add); //&函数名和函数名都是函数地址
//   int (*pa)(int, int) = Add;
//   printf("%d\n",(*pa)(3, 3));
//   return 0;
// }
// #include <stdio.h>
// int Add(int x, int y)
// {
//   int z = 0;
//   z = x + y;
//   return z;
// }
// int Sub(int x, int y)
// {
//   int z = 0;
//   z = x - y;
//   return z;
// }
// int Mul(int x, int y)
// {
//   int z = 0;
//   z = x * y;
//   return z;
// }
// int Div(int x, int y)
// {
//   int z = 0;
//   z = x / y;
//   return z;
// }
// int main()
// {
//   // 指针数组
//   // int * arr[5];
//   //需要一个数组 这个数组可以存放4个函数的地址-函数指针的数组
//   int (*parr[4])(int,int) ={Add,Sub, Mul,Div};
//   int i=0;
//   for(i-0;i<4;i++)
//   {
//     printf("%d\n",parr[i](2,3));
//   }
//   return 0;
// }
# include<stdio.h>
void menu()
{
  printf("******************\n");
  printf("***1.add  2.sub***\n");
  printf("***3.mul  4.div***\n");
  printf("***   0.exit   ***\n");
  printf("******************\n");
}

int Add(int x, int y)
{
  return x+y;
}
int Sub(int x, int y)
{
  int z = 0;
  z = x - y;
  return z;
}
int Mul(int x, int y)
{
  int z = 0;
  z = x * y;
  return z;
}
int Div(int x, int y)
{
  int z = 0;
  z = x / y;
  return z;
}
int main()
{
  int input = 0;
  int x=0;
  int y=0;

  do
  {
    menu();
    printf("请选择：>");
    scanf("%d", &input);
    
    scanf("%d%d",&x,&y);
    switch (input)
    {
    case 1:
      printf("请输入两个数:>");
      printf("%d\n",Add(x,y));
      break;
    case 2:
      printf("请输入两个数:>");
      printf("%d\n",Sub(x,y));
      break;
    case 3:
      printf("请输入两个数:>");
      printf("%d\n",Mul(x,y));
      break;
    case 4:
      printf("请输入两个数:>");
      printf("%d\n",Div(x,y));
      break;
    case 0:
      printf("退出\n");
      break;
    default:
      printf("选择错误\n");
      break;
    }
  } while (input);
  return 0;
}