#include <stdio.h>

//c语言 预处理
//源文件--->编译 链接 --->可执行文件---->运行
//编译环境                     运行环境

//源文件经过编译器处理生成目标文件 经过链接器处理 生成目标程序
//编译：1：预编译 2：编译 3：汇编

int main1() {
    int arr[10] = {0};

    int i = 0;
    for(i = 0 ;i < 10;i++)
    {
        arr[i] = i;
    }
    for(i = 0; i< 10; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}
//预处理 符号
int main2()
{
    printf("%s\n",__FILE__); //D:/c-project/pro-28/main.c 当前文件所在源文件的名称
    printf("%d\n",__LINE__); //28 代码所在的行号
    printf("%s\n",__DATE__);//Sep 15 2022 获取当前日期
    printf("%s\n",__TIME__); //09:56:18 获取当前时间


    //写日志文件
    int i= 0;
    int arr[10] = {0};
    FILE* pf = fopen("C:\\log.txt","w");
    for(i = 0; i<10; i++)
    {
        arr[i] = i;
        //将制定格式的字符 传输到 流中
        fprintf(pf,"file:%s line:%d date:%s time:%s i=%d\n",__FILE__,__LINE__,__DATE__,__TIME__,i);

        printf("%s\n",__FUNCTION__ ); //获取当前函数名称

    }
    fclose(pf);
    pf = NULL;
    for( i= 0; i< 10; i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main3()
{
    //__STDC__：编译器是否遵循c语言标准ANSI C  返回1 或者 未定义
    printf("%d\n",__STDC__); //1
}

/*
#define
#include

#pragma pack(4) 定义对其数为4
#pragma

#if
#endif

#line
*/

//#define 预处理指
// 1:定义标识符
// 2：定义宏
#define MAX 10010
#define STR "hehe"

#define reg register
//定义死循环for(;;)
#define do_forever for(;;)
int main4()
{
    int max = MAX; //标识符的使用
    printf("%d\n",max);

    printf("%s\n",STR);

    reg int a;
    register int b;//相同效果

    do_forever; //死循环

}

//定义宏 宏不能递归
//#define SQUARE(x) x*x
#define SQUARE(x) (x)*(x) //改造
#define DOUBLE(x) ((x)+(x))
int main()
{
//    int a  = SQUARE(5); //求a的平方
    //宏不是传参 而是替换 5+1*5+1
    int a  = SQUARE(5+1); //11
    printf("%d\n",a);


    int x = 10;
    int ret = 10* DOUBLE(10); //写宏的时候 不要吝啬()
    //10* 10+10
    printf("%d\n",ret);

}
//注意:操作符的优先级如果不相同时 可能会导致发生意外


