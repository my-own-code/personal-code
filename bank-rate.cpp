#include <iostream>
#include<fstream>
#include<cstdio>
using namespace std;
char* str[9]={"活期存款:","整存整取3个月:","整存整取6个月:","整存整取一年:","整存整取两年:","整存整取五年:"
                  ,"零存整取一年:","零存整取三年:","零存整取五年:"};
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
    printf("请输入所要修改的利率的对应序号：");
    scanf("%d",&choice);
    printf("请输入修改后的利率：");
    scanf("%f",&changerate);
    rate[choice-1]=changerate;
    printf("修改完毕\n");
    return 0;
}

int Demand()
{
    int a,b;
    int style;
    printf("请选择存款类型\n1.活期存款\n2.整存整取\n3.零存整取\n");
    scanf("%d",&style);
    if(style==1)
    {
       printf("利率为：%f",rate[0]);
    }
    if(style==2)
    {
       printf("请选择存款年限:\n1.3个月\n2.6个月\n3.一年\n4.两年\n5.五年\n");
       scanf("%d",&a);
       printf("%f",rate[a]);
    }
    if(style==3)
    {
        printf("请选择存款年限:\n1.一年\n2.三年\n3.五年\n");
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
    printf("请输入你要存取的金额:");
    scanf("%f",&money);
    printf("请选择存款类型\n1.活期存款\n2.整存整取\n3.零存整取\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("请输入存款年限:");
        scanf("%d",&year);
        profit=money*rate[0]*year;
        printf("%f",profit);
    }
    if(ch==2)
    {
       printf("请选择存款年限:\n1.3个月\n2.6个月\n3.一年\n4.两年\n5.五年\n");
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
        printf("请选择存款年限:\n1.一年\n2.三年\n3.五年\n");
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
    printf("1、建立新的利率表\n2、修改利率\n3、查询利率\n4、计算所得利息\n");
    printf("请选择你所需要的服务:");
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

