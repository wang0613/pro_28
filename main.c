#include <stdio.h>

//c���� Ԥ����
//Դ�ļ�--->���� ���� --->��ִ���ļ�---->����
//���뻷��                     ���л���

//Դ�ļ�������������������Ŀ���ļ� �������������� ����Ŀ�����
//���룺1��Ԥ���� 2������ 3�����

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
//Ԥ���� ����
int main2()
{
    printf("%s\n",__FILE__); //D:/c-project/pro-28/main.c ��ǰ�ļ�����Դ�ļ�������
    printf("%d\n",__LINE__); //28 �������ڵ��к�
    printf("%s\n",__DATE__);//Sep 15 2022 ��ȡ��ǰ����
    printf("%s\n",__TIME__); //09:56:18 ��ȡ��ǰʱ��


    //д��־�ļ�
    int i= 0;
    int arr[10] = {0};
    FILE* pf = fopen("C:\\log.txt","w");
    for(i = 0; i<10; i++)
    {
        arr[i] = i;
        //���ƶ���ʽ���ַ� ���䵽 ����
        fprintf(pf,"file:%s line:%d date:%s time:%s i=%d\n",__FILE__,__LINE__,__DATE__,__TIME__,i);

        printf("%s\n",__FUNCTION__ ); //��ȡ��ǰ��������

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
    //__STDC__���������Ƿ���ѭc���Ա�׼ANSI C  ����1 ���� δ����
    printf("%d\n",__STDC__); //1
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
int main4()
{
    int max = MAX; //��ʶ����ʹ��
    printf("%d\n",max);

    printf("%s\n",STR);

    reg int a;
    register int b;//��ͬЧ��

    do_forever; //��ѭ��

}

//����� �겻�ܵݹ�
//#define SQUARE(x) x*x
#define SQUARE(x) (x)*(x) //����
#define DOUBLE(x) ((x)+(x))
int main()
{
//    int a  = SQUARE(5); //��a��ƽ��
    //�겻�Ǵ��� �����滻 5+1*5+1
    int a  = SQUARE(5+1); //11
    printf("%d\n",a);


    int x = 10;
    int ret = 10* DOUBLE(10); //д���ʱ�� ��Ҫ����()
    //10* 10+10
    printf("%d\n",ret);

}
//ע��:�����������ȼ��������ͬʱ ���ܻᵼ�·�������


