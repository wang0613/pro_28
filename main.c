#include <stdio.h>
#include <stdlib.h>

//c语言 预处理
//源文件--->编译 链接 --->可执行文件---->运行
//编译环境                     运行环境

//源文件经过编译器处理生成目标文件 经过链接器处理 生成目标程序
//编译：1：预编译 2：编译 3：汇编

int main1() {
    int arr[10] = {0};

    int i = 0;
    for (i = 0; i < 10; i++) {
        arr[i] = i;
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

//预处理 符号
int main2() {
    printf("%s\n", __FILE__); //D:/c-project/pro-28/main.c 当前文件所在源文件的名称
    printf("%d\n", __LINE__); //28 代码所在的行号
    printf("%s\n", __DATE__);//Sep 15 2022 获取当前日期
    printf("%s\n", __TIME__); //09:56:18 获取当前时间


    //写日志文件
    int i = 0;
    int arr[10] = {0};
    FILE *pf = fopen("C:\\log.txt", "w");
    for (i = 0; i < 10; i++) {
        arr[i] = i;
        //将制定格式的字符 传输到 流中
        fprintf(pf, "file:%s line:%d date:%s time:%s i=%d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);

        printf("%s\n", __FUNCTION__); //获取当前函数名称

    }
    fclose(pf);
    pf = NULL;
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
}

int main3() {
    //__STDC__：编译器是否遵循c语言标准ANSI C  返回1 或者 未定义
    printf("%d\n", __STDC__); //1
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

int main4() {
    int max = MAX; //标识符的使用
    printf("%d\n", max);

    printf("%s\n", STR);

    reg int a;
    register int b;//相同效果

    do_forever; //死循环

}

//定义宏 宏不能递归
//#define SQUARE(x) x*x
#define SQUARE(x) (x)*(x) //改造
#define DOUBLE(x) ((x)+(x))

int main5() {
//    int a  = SQUARE(5); //求a的平方
    //宏不是传参 而是替换 5+1*5+1
    int a = SQUARE(5 + 1); //11
    printf("%d\n", a);


    int x = 10;
    int ret = 10 * DOUBLE(10); //写宏的时候 不要吝啬()
    //10* 10+10
    printf("%d\n", ret);

}

//注意:操作符的优先级如果不相同时 可能会导致发生意外
void print(int a) {
    printf("the value of a is %d\n", a);

}

#define PRINT(X) printf("the value of "#X" is %d\n",X)


int main6() {
    int a = 10;
//    printf("the value of a is %d\n",a);
    int b = 20;
//    print(b);

    PRINT(b);
}

#define CAT(x, y) x##y

int main7() {
    int CLASS11 = 2019;
    printf("%d\n", CAT(CLASS, 11));  //CLASS##11 == CLASS11
    return 0;
}

#define MAX(X, Y) (X)>(Y)?(X):(Y)

int main8() {
    int a = 10;
    int b = 20;
    //宏的参数 具有副作用 完全替换代码 a++执行了两次
    printf("%d ", MAX(a++, b++));
    printf("%d %d", a, b);//21 11 22

//    宏与函数的区别：
//    1、宏做的是简单的字符串替换，不受类型限制；而函数是参数的传递，受到参数类型的限制。
//    2、宏体替换宏名是在编译之前就完成的，函数参数的调用是在函数执行时将实参传给形参的。
//    3、宏参数的替换是不经过计算的，有可能会带有副作用，所以我们在写宏体的时候一般在能加括号的地方都不要吝啬括号
//       但有时候这也不能解决副作用的问题。函数在传参时传的是值，不会产生副作用。
//    4、因为函数是在执行期间调用的，所以可以进行调试；宏在编译前完成的，所以不可以进行调试。
//    5、函数支持递归，宏不支持。
//    6、函数在调用时会产生时间和空间上的开销；宏在调用时则没有，因为宏进行的只是简单的字符串替换。
//    7、如果使用宏比较多，宏体在展开时会产生大量的代码，大大降低运行时间。

}

#define SIZEOF(type) sizeof(type)

#define MALLOC(num, type) (type*)(malloc(num*sizeof(type)))

int main9() {
    int a = SIZEOF(int); //宏是类型无关的  可以传递类型
    printf("%d ", a);//4

//    int pi = (int *) malloc(4 * sizeof(int));
    int p = MALLOC(40, int);

}
//命令行定义
//gcc test.c -D SZ=10 在编译时指定sz为10

#define DEBUG //控制是否编译

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int i = 0;
    for (i = 0; i < 10; i++) {
        arr[i] = 0;
#ifdef DEBUG  //条件编译 满足条件进行编译 不满足不参与编译
        printf("%d ", arr[i]);
#endif
    }

}