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
int main()
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
        fprintf(pf,"file:%s line:%d date:%s time:%s i=%d\n",__FILE__,__LINE__,__DATE__,__TIME__,i);
    }
    fclose(pf);
    pf = NULL;
    for( i= 0; i< 10; i++)
    {
        printf("%d\n",arr[i]);
    }
}
