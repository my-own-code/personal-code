#include <iostream>
#include<fstream>
#include<cstdio>
using namespace std;
char* str[9]={"���ڴ��:","������ȡ3����:","������ȡ6����:","������ȡһ��:","������ȡ����:","������ȡ����:"
                  ,"�����ȡһ��:","�����ȡ����:","�����ȡ����:"};
float rate[9];

int Creat()
{
    int i;
    for(i=0;i<9;i++)
    {
        printf("%s",str[i]);
        scanf("%f",&rate[i]);
    }
    return 0;
}

int Change()
{
    int j;
    int choice;
    float changerate;
    for(j=0;j<9;j++)
    {
        printf("%d.%s\n",j+1,str[j]);
    }
    printf("��������Ҫ�޸ĵ����ʵĶ�Ӧ��ţ�");
    scanf("%d",&choice);
    printf("�������޸ĺ�����ʣ�");
    scanf("%f",&changerate);
    rate[choice-1]=changerate;
    printf("�޸����\n");
    return 0;
}

int Demand()
{
    int a,b;
    int style;
    printf("��ѡ��������\n1.���ڴ��\n2.������ȡ\n3.�����ȡ\n");
    scanf("%d",&style);
    if(style==1)
    {
       printf("����Ϊ��%f",rate[0]);
    }
    if(style==2)
    {
       printf("��ѡ��������:\n1.3����\n2.6����\n3.һ��\n4.����\n5.����\n");
       scanf("%d",&a);
       printf("%f",rate[a]);
    }
    if(style==3)
    {
        printf("��ѡ��������:\n1.һ��\n2.����\n3.����\n");
        scanf("%d",&b);
        printf("%f",rate[b+5]);
    }
    return 0;
}

int Calculate()
{
    int ch;
    int c,d;
    float money,profit;
    int year;
    printf("��������Ҫ��ȡ�Ľ��:");
    scanf("%f",&money);
    printf("��ѡ��������\n1.���ڴ��\n2.������ȡ\n3.�����ȡ\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("������������:");
        scanf("%d",&year);
        profit=money*rate[0]*year;
        printf("%f",profit);
    }
    if(ch==2)
    {
       printf("��ѡ��������:\n1.3����\n2.6����\n3.һ��\n4.����\n5.����\n");
       scanf("%d",&c);
       if(c==1)
       {
         profit=money*rate[c]*0.25;
         printf("%f",profit);
       }
       if(c==2)
       {
         profit=money*rate[c]*0.5;
         printf("%f",profit);
       }
       if(c==3)
       {
         profit=money*rate[c];
         printf("%f",profit);
       }
       if(c==4)
       {
         profit=money*rate[c]*2;
         printf("%f",profit);
       }
       if(c==5)
       {
         profit=money*rate[c]*5;
         printf("%f",profit);
       }
    }
    if(ch==3)
    {
        printf("��ѡ��������:\n1.һ��\n2.����\n3.����\n");
        scanf("%d",&d);
        if(d==1)
        {
         profit=money*rate[d+5]*1;
         printf("%f",profit);
        }
        if(d==2)
        {
         profit=money*rate[d+5]*2;
         printf("%f",profit);
        }
        if(d==3)
        {
         profit=money*rate[d+5]*3;
         printf("%f",profit);
        }
    }
    return 0;
}

int out()
{
    int q;
    printf("1�������µ����ʱ�\n2���޸�����\n3����ѯ����\n4������������Ϣ\n");
    printf("��ѡ��������Ҫ�ķ���:");
    scanf("%d",&q);
    return q;
}

int main()
{
   char cho;
   while(1)
   {
   cho=out();
   switch(cho)
   {
       case 1:
           Creat();
           break;
       case 2:
           Change();
           break;
       case 3:
           Demand();
           break;
       case 4:
           Calculate();
           break;
       default:
           return 0;
   };
   }
return 0;
}

