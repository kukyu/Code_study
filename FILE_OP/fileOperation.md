# 文件读取操作

## 文件缓冲区

内存先放入内存缓冲区，放满后送入程序数据区

## 文件指针

文件类型指针

每个被使用的文件都在内存中开辟了相应的文件信息区，用来存放文件的相关信息（如文件的名字，文件状态和当前的位置）
这些信息保存在结构体变量中，该结构体有系统声明，取名 FILE。

`FILE *pf = fopen("test.txt", "wb");`//文件类型指针

e.g.

```C
#include <stdio.h>
int main()
{
    int a = 10000;
    FILE *pf = fopen("test.txt", "wb");
    fwrite(&a, 4, 1, pf); //二进制写写到文件中
    fclose(pf);
    pf = NULL;
    return 0;
}
```

## 文件打开和关闭

```C
#include <stdio.h>
int main()
{
    // 打开文件
    FILE *pf = fopen("test.txt", "r"); //"r"只读
    // ..表示上级路径
    // fopen("../test.txt", "r");
    // fopen("../../test.txt", "r");

    fclose(pf); //关闭文件

    return 0;
}
```

### 文件使用方式

"r" 只读

"w" 只写

"a" 追加

"rb" 二进制只读

"r+" 为了读和写 打开一个文件

"w+" 为了读和写 写入一个文件

"a+" 为了读和写 追加一个文件

## 文件顺序读写

fputc 写操作

```C
#include <stdio.h>
int main()
{

    FILE *pfWrite = fopen("test.txt", "w");
    fputc('i', pfWrite); //写入

    fclose(pfWrite);
    pfWrite = NULL;

    return 0;
}

```

fgetc 读操作

```C
#include <stdio.h>
int main()
{

    FILE *pfRead = fopen("test.txt", "r");
    // 读文件
    printf("%c", fgetc(pfRead));
    printf("%c", fgetc(pfRead));//一次读一个字符
    fclose(pfRead);
    pfRead = NULL; //防止指针变成野指针
    return 0;
}

```

键盘输入和输出

```C
#include <stdio.h>
int main()
{
    int ch =fgetc(stdin); //从键盘输入
    fputc(ch, stdout); //输出屏幕
    return 0;
}
```

fgets 读取一行

```C
#include <stdio.h>
int main()
{
    char buf[1024] = {0};
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        return 0;
    }
    // 读文件
    fgets(buf, 1024, pf); //读取一行
    printf("%s", buf);
    fgets(buf, 1024, pf); //读取第二行
    // printf("%s", buf);
    puts(buf);
    fclose(pf);
    pf = NULL;

    return 0;
}
```

fputs 写入一行

```C
#include <stdio.h>
int main()
{
    char buf[1024] = {0};
    FILE *pf = fopen("test.txt", "w");
    if (pf == NULL)
    {
        return 0;
    }
    // 读文件
    fputs("hello\n", pf); //写入一行 不会自动换行
    fputs("world\n", pf);
    fclose(pf);
    pf = NULL;

    return 0;
}
```

键盘输入读取

```C

#include <stdio.h>
int main()
{
    // 从键盘读取一行信息
    char buf[1024] = {0};
    fgets(buf,1024,stdin); //从键盘输入
    fputs(buf, stdout);  //输出
    return 0;
}
```

fprintf

```C
// fprintf fscanf
#include <stdio.h>
struct S
{
    float score;
    int n;
    char arr[10];
};

int main()
{
    struct S s = {3.12f, 100, "bit"};
    FILE *pf = fopen("test.txt", "w");
    if (pf == NULL)
    {
        return 0;
    }
    // 格式化形式写文件
    fprintf(pf,"%f%d%s", s.score,s.n,s.arr);

    fclose(pf);
    pf = NULL;
    return 0;
}
```

fscanf

```C
//  fscanf
#include <stdio.h>
struct S
{
    float score;
    int n;
    char arr[10];
};

int main()
{
    struct S s = {0};
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        return 0;
    }
    // 格式化形式输入文件
    fscanf(pf, "%f%d%s",&(s.score),&(s.n),&(s.arr));
    printf("%f%d%s",s.score,s.n,s.arr);
    fclose(pf);
    pf = NULL;
    return 0;
}
```

scanf/printf 针对标准输入输出流

fscanf/fprintf 针对所有输入输出流

sscanf 从字符串中读取格式化的数据

sprintf 把格式化的数据输出到字符串

swscanf/swprintf  
