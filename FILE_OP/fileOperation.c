// #include <stdio.h>

// int main()
// {
//     int a = 10000;
//     FILE *pf = fopen("test.txt", "wb");
//     fwrite(&a, 4, 1, pf); //二进制写写到文件中
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     // 打开文件
//     FILE *pf = fopen("test.txt", "r"); //"r"只读
//     // ..表示上级路径
//     // fopen("../test.txt", "r");
//     // fopen("../../test.txt", "r");

//     fclose(pf); //关闭文件

//     return 0;
// }

// #include <stdio.h>
// int main()
// {

//     FILE *pfWrite = fopen("test.txt", "w");
//     fputc('b', pfWrite);
//     fputc('i', pfWrite);

//     fclose(pfWrite);
//     pfWrite = NULL;

//     return 0;
// }

// #include <stdio.h>
// int main()
// {

//     FILE *pfRead = fopen("test.txt", "r");
//     // 读文件
//     printf("%c", fgetc(pfRead));
//     printf("%c", fgetc(pfRead));//一次读一个字符
//     fclose(pfRead);
//     pfRead = NULL; //防止指针变成野指针
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     int ch =fgetc(stdin); //从键盘输入
//     fputc(ch, stdout); //输出屏幕
//     return 0;
// }

// // fgets()
// #include <stdio.h>
// int main()
// {
//     char buf[1024] = {0};
//     FILE *pf = fopen("test.txt", "r");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 读文件
//     fgets(buf, 1024, pf); //读取一行
//     printf("%s", buf);
//     fgets(buf, 1024, pf); //读取第二行
//     // printf("%s", buf);
//     puts(buf);
//     fclose(pf);
//     pf = NULL;

//     return 0;
// }

// fputs()
// #include <stdio.h>
// int main()
// {
//     char buf[1024] = {0};
//     FILE *pf = fopen("test.txt", "w");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 读文件
//     fputs("hello\n", pf); //写入一行 不会自动换行
//     fputs("world\n", pf);
//     fclose(pf);
//     pf = NULL;

//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     // 从键盘读取一行信息
//     char buf[1024] = {0};
//     fgets(buf,1024,stdin); //从键盘输入
//     fputs(buf, stdout);  //输出
//     return 0;
// }

// // fprintf fscanf
// #include <stdio.h>
// struct S
// {
//     float score;
//     int n;
//     char arr[10];
// };

// int main()
// {
//     struct S s = {3.12f, 100, "bit"};
//     FILE *pf = fopen("test.txt", "w");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 格式化形式写文件
//     fprintf(pf,"%f%d%s", s.score,s.n,s.arr);

//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

//  fscanf
// #include <stdio.h>
// struct S
// {
//     float score;
//     int n;
//     char arr[10];
// };

// int main()
// {
//     struct S s = {0};
//     FILE *pf = fopen("test.txt", "r");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 格式化形式输入文件
//     fscanf(pf, "%f%d%s",&(s.score),&(s.n),&(s.arr));
//     printf("%f%d%s",s.score,s.n,s.arr);
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// #include <stdio.h>
// struct S
// {
//     char name[20];
//     int n;
//     double score;

// };

// int main()
// {
//     // 二进制写文件
//     struct S s = {"张三", 20, 55.6};
//     FILE *pf = fopen("test.txt", "wb");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 二进制形式写文件
//     fwrite(&s, sizeof(struct S), 1, pf);
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// #include <stdio.h>
// struct S
// {
//     char name[20];
//     int age;
//     double score;

// };

// int main()
// {
//     // 二进制读文件
//     // struct S s = {"张三", 20, 55.6};
//     struct S tmp = {0};

//     FILE *pf = fopen("test.txt", "rb");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 二进制形式 读文件
//     fread(&tmp,sizeof(struct S), 1, pf);
//     printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     FILE *pf = fopen("test.txt", "r");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 1.定位文件指针
//     fseek(pf, 1, SEEK_CUR);   // 文件名 偏移量 文件指针当前位置(
//         //SEEK_CUR 文件指针当前位置 SEEK_END 末尾位置   EEK_SET 文件起始位置
//     //2，读取文件
//     int ch = fgetc(pf);
//     printf("%c\n",ch);
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     FILE *pf = fopen("test.txt", "r");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 1.定位文件指针
//     fseek(pf, -2, SEEK_END);
//     int pos = ftell(pf); // 计算偏移量
//     printf("%d\n",pos);
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

#include <stdio.h>
int main()
{
    // feof(); //EOF-end of file - 文件结束标志
    // 不能用feof函数的返回值判断文件是否结束
    // 应用于读取结束后判断是否读取失败结束，还是遇到文件尾结束
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        return 0;
    }
   
    fclose(pf);
    pf = NULL;
    return 0;
}