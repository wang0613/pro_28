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
int main()
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
        fprintf(pf,"file:%s line:%d date:%s time:%s i=%d\n",__FILE__,__LINE__,__DATE__,__TIME__,i);
    }
    fclose(pf);
    pf = NULL;
    for( i= 0; i< 10; i++)
    {
        printf("%d\n",arr[i]);
    }
}
