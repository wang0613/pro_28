#include <stdio.h>
#include <stdlib.h>

//c���� Ԥ����
//Դ�ļ�--->���� ���� --->��ִ���ļ�---->����
//���뻷��                     ���л���

//Դ�ļ�������������������Ŀ���ļ� �������������� ����Ŀ�����
//���룺1��Ԥ���� 2������ 3�����

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

//Ԥ���� ����
int main2() {
    printf("%s\n", __FILE__); //D:/c-project/pro-28/main.c ��ǰ�ļ�����Դ�ļ�������
    printf("%d\n", __LINE__); //28 �������ڵ��к�
    printf("%s\n", __DATE__);//Sep 15 2022 ��ȡ��ǰ����
    printf("%s\n", __TIME__); //09:56:18 ��ȡ��ǰʱ��


    //д��־�ļ�
    int i = 0;
    int arr[10] = {0};
    FILE *pf = fopen("C:\\log.txt", "w");
    for (i = 0; i < 10; i++) {
        arr[i] = i;
        //���ƶ���ʽ���ַ� ���䵽 ����
        fprintf(pf, "file:%s line:%d date:%s time:%s i=%d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);

        printf("%s\n", __FUNCTION__); //��ȡ��ǰ��������

    }
    fclose(pf);
    pf = NULL;
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
}

int main3() {
    //__STDC__���������Ƿ���ѭc���Ա�׼ANSI C  ����1 ���� δ����
    printf("%d\n", __STDC__); //1
}

/*
#define
#include

#pragma pack(4) ���������Ϊ4
#pragma

#if
#endif

#line
*/

//#define Ԥ����ָ
// 1:�����ʶ��
// 2�������
#define MAX 10010
#define STR "hehe"

#define reg register
//������ѭ��for(;;)
#define do_forever for(;;)

int main4() {
    int max = MAX; //��ʶ����ʹ��
    printf("%d\n", max);

    printf("%s\n", STR);

    reg int a;
    register int b;//��ͬЧ��

    do_forever; //��ѭ��

}

//����� �겻�ܵݹ�
//#define SQUARE(x) x*x
#define SQUARE(x) (x)*(x) //����
#define DOUBLE(x) ((x)+(x))

int main5() {
//    int a  = SQUARE(5); //��a��ƽ��
    //�겻�Ǵ��� �����滻 5+1*5+1
    int a = SQUARE(5 + 1); //11
    printf("%d\n", a);


    int x = 10;
    int ret = 10 * DOUBLE(10); //д���ʱ�� ��Ҫ����()
    //10* 10+10
    printf("%d\n", ret);

}

//ע��:�����������ȼ��������ͬʱ ���ܻᵼ�·�������
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
    //��Ĳ��� ���и����� ��ȫ�滻���� a++ִ��������
    printf("%d ", MAX(a++, b++));
    printf("%d %d", a, b);//21 11 22

//    ���뺯��������
//    1���������Ǽ򵥵��ַ����滻�������������ƣ��������ǲ����Ĵ��ݣ��ܵ��������͵����ơ�
//    2�������滻�������ڱ���֮ǰ����ɵģ����������ĵ������ں���ִ��ʱ��ʵ�δ����βεġ�
//    3����������滻�ǲ���������ģ��п��ܻ���и����ã�����������д�����ʱ��һ�����ܼ����ŵĵط�����Ҫ��������
//       ����ʱ����Ҳ���ܽ�������õ����⡣�����ڴ���ʱ������ֵ��������������á�
//    4����Ϊ��������ִ���ڼ���õģ����Կ��Խ��е��ԣ����ڱ���ǰ��ɵģ����Բ����Խ��е��ԡ�
//    5������֧�ֵݹ飬�겻֧�֡�
//    6�������ڵ���ʱ�����ʱ��Ϳռ��ϵĿ��������ڵ���ʱ��û�У���Ϊ����е�ֻ�Ǽ򵥵��ַ����滻��
//    7�����ʹ�ú�Ƚ϶࣬������չ��ʱ����������Ĵ��룬��󽵵�����ʱ�䡣

}

#define SIZEOF(type) sizeof(type)

#define MALLOC(num, type) (type*)(malloc(num*sizeof(type)))

int main9() {
    int a = SIZEOF(int); //���������޹ص�  ���Դ�������
    printf("%d ", a);//4

//    int pi = (int *) malloc(4 * sizeof(int));
    int p = MALLOC(40, int);

}
//�����ж���
//gcc test.c -D SZ=10 �ڱ���ʱָ��szΪ10

#define DEBUG //�����Ƿ����

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int i = 0;
    for (i = 0; i < 10; i++) {
        arr[i] = 0;
#ifdef DEBUG  //�������� �����������б��� �����㲻�������
        printf("%d ", arr[i]);
#endif
    }

}