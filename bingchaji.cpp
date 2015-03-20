#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxSize 100
typedef char ElemType;
typedef int P;
typedef struct
{
    ElemType data;
    P par;
    int count;
} REset;
typedef struct
{
    int number;
    REset set[MaxSize];
} sets;
void creat(sets &C)
{
    P i;
    C.number = 0;
    for (i = 0; i < MaxSize + 1; i++)
    {
        C.set[i].par = 0;
        C.set[i].count = 0;
    }
}
void AddNewset(ElemType x,sets &C)
{
    C.number++;
    C.set[C.number].data = x;
    C.set[C.number].par = 0;
    C.set[C.number].count = 1;
}
void Union(P A,P B,sets &C)
{
    if (C.set[A].count >= C.set[B].count)
    {
        C.set[B].par = A;
        C.set[A].count = C.set[A].count + C.set[B].count;
    }
    else
    {
        C.set[A].par = B;
        C.set[B].count = C.set[A].count + C.set[B].count;
    }
}
P FindP(P x,sets C)
{
    P temp;
    temp = x;
    while (C.set[temp].par != 0)
        temp = C.set[temp].par;
    return(temp);
}

P FindPosition(ElemType x,sets C)
{
    P i;
    i = 1;
    for (i = 1; i <= C.number; i++)
        if (x == C.set[i].data)
            return(i);
    return(-1);
}
void ShowAll(sets C)
{
    printf("要进行分类的元素:");
    P i;
    for (i = 1; i <= C.number; i++)
        cout<<C.set[i].data<<" ";
    cout<<endl<<endl;
}
void Equivalence(P A,P B,sets &C)
{
    P x,y;
    if ((A == -1) || (B == -1))
        printf("false\n");
    else
    {
        x = FindP(A,C);
        y = FindP(B,C);
        if (x != y)
        {
            Union(x,y,C);
            printf("已合并.\n");
        }
        else
            printf("两元素已经属于同一等价类.\n");
    }
}

void Showsets(sets C)
{
    printf("等价类如下:\n");
    P x,y;
    for (x = 1; x <= C.number; x++)
        if (C.set[x].par == 0)
        {
            cout<<"{"<<C.set[x].data;
            for (y = 1; y <= C.number; y++)
                if ((FindP(y,C) == x) && (y != x))
                    cout<<","<<C.set[y].data;
            cout<<"}"<<endl;
        }
}
int main()
{
    sets C;
    ElemType x,y;
    creat(C);
    cout<<"请输入要加入集合的元素(输入为""#""则输入结束):";
    cin>>x;
    do
    {
        AddNewset(x,C);
        cout<<"请输入要加入集合的元素(输入为""#""则输入结束):";
        cin>>x;
    }
    while(x != '#');
    printf("集合元素输入完毕!\n");
    ShowAll(C);
    printf("请输入等价的元素(输入为""# #""则输入结束):");
    cin>>x>>y;
    do
    {
        Equivalence(FindPosition(x,C),FindPosition(y,C),C);
        printf("请输入等价的元素(输入为""# #""则输入结束):");
        cin>>x>>y;
    }
    while((x != '#') && (y != '#'));
    cout<<endl;
    Showsets(C);
    return(0);
}
