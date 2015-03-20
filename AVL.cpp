#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class linknod;
class avl
{
    friend class linknod;
public:
    avl();
    int instalnod(int);//�����㺯��
    int deletnod(int);//ɾ����㺯��
    int findnod(int,linknod*);//���ҽ�㺯��
    void pushs(linknod*);//���·����ջ
    linknod* pope();//���·����ջ
    void subll(linknod*);//����������
    void sublr(linknod*);//���������ת
    void subrr(linknod*);//����������
    void subrl(linknod*);//���Һ�����
    void display(linknod*);
    void displaym(linknod*);
    linknod *ptr;//�����ָ��
    linknod *first;
private:
    linknod *subl;//����ָ��
    linknod *subr;//����ָ��
    linknod* stacts[100];//·�����ҽ��洢ջ
    int top;//ջ��ָ��
    int botem;//ջ��ָ��
};
class linknod
{
    friend class avl;
public:
    linknod();
private:
    int bf;//ƽ������
    int data;
    linknod *lchild;
    linknod *rchild;
    linknod *perint;
};
avl::avl()
{
    subl=0;
    subr=0;
    ptr=0;
    top=-1;
    botem=-1;
    for(int i=0; i<100; i++)
        stacts[i]=0;
}
linknod::linknod()
{
    perint=0;
    lchild=0;
    rchild=0;
    data=0;
    bf=0;
}
void avl::display(linknod* n)
{
    if(n!=0)
    {
        cout<<n->data<<"   ";
        display(n->lchild);
        display(n->rchild);
    }
}
void avl::displaym(linknod*n)
{
    if(n!=0)
    {
        displaym(n->lchild);
        cout<<n->data<<"   ";
        displaym(n->rchild);
    }
}
void avl::pushs(linknod* n)
{
    botem=-1;
    top++;
    stacts[top]=n;
}
linknod* avl::pope()
{
    linknod* n;
    botem=-1;
    n=stacts[top];
    top--;
    return n;
}
int avl::deletnod(int n)
{
    linknod *pr=0,*p=ptr,*q;//*ppr;
    int d,tag=0,tag1=0;//dd=0
    top=-1;//��ʼ��ջ��ָ��
    while(p!=0)//����Ҫɾ���Ľ�㲢��¼����·��
    {
        if(n==p->data)
            break;
        pr=p;
        pushs(pr);
        if(n<p->data)
            p=p->lchild;
        else
            p=p->rchild;
    }
    if(p==0)
        return -1;
    if(p->lchild!=0&&p->rchild!=0)
    {
        pr=p;
        pushs(pr);
        q=p->lchild;
        while(q->rchild!=0)
        {
            pr=q;
            pushs(pr);
            q=q->rchild;
        }
        p->data=q->data;
        p=q;
    }
    if(p->lchild!=0)
        q=p->lchild;
    else
    {
        q=p->rchild;
    }
    if(pr==0)
        ptr=q;
    else
    {
        if(pr->lchild==p)
        {
            pr->lchild=q;
            if(pr->lchild!=0)
                pr->lchild->perint=pr;
            tag=1;
        }
        else
        {
            pr->rchild=q;
            if(pr->rchild!=0)
                pr->rchild->perint=pr;
            tag1=1;
        }
        while(top!=botem)
        {
            pr=pope();
            if(pr->lchild!=0||pr->rchild!=0)
            {
                if(pr->rchild==q)
                {
                    pr->bf--;
                }
                if(pr->lchild==q)
                {
                    pr->bf++;
                }
            }
            else
            {
                if(tag==1)
                {
                    pr->bf++;
                    tag=0;
                }
                if(tag1==1)
                {
                    pr->bf--;
                    tag1=0;
                }
            }
            if(pr->bf==1||pr->bf==-1)
                break;
            if(pr->bf!=0)
            {
                if(pr->bf<0)
                {
                    d=-1;
                    q=pr->lchild;
                }
                else
                {
                    d=1;
                    q=pr->rchild;
                }
                if(q->bf==0)
                {
                    if(d==-1)
                    {
                        subrr(pr);
                    }
                    else
                    {
                        subll(pr);
                    }
                    break;
                }
                if(q->bf==d)
                {
                    if(d==-1)
                        subrr(pr);
                    else
                        subll(pr);
                }
                else
                {
                    if(d==-1)
                        sublr(pr);
                    else
                        subrl(pr);//
                }
            }
            q=pr;
        }
    }
    delete p;
    return 1;
}
int avl::findnod(int n,linknod* t)
{
    int tag=0;
    while(t!=0)
    {
        if(n<t->data)
            t=t->lchild;
        else
        {
            if(n>t->data)
                t=t->rchild;
            else if(n==t->data)
            {
                tag=1;
                break;
            }
        }
    }
    if(tag!=1)
        return 0;
    else
        return 1;
}
int avl::instalnod(int n)
{
    linknod *p=0;
    linknod *pr=0;
    //linknod *r=0;
    int d;
    p=ptr;
    while(p!=0)
    {
        if(n==p->data)
        {
            return -1;
        }
        pr=p;
        pushs(pr);//�洢����·��
        if(n<p->data)//���ݲ������Ĵ�С�жϲ���λ��
            p=p->lchild;
        else
            p=p->rchild;
    }
    p=new linknod;
    p->data=n;
    p->bf=0;
    if(ptr==0)
    {
        ptr=p;
        first=p;
        p->perint=0;
        return 1;
    }
    p->perint=pr;
    if(n<pr->data)
        pr->lchild=p;
    else
        pr->rchild=p;
    while(top!=botem)
    {
        linknod *temp;
        temp=pope();
        if(p==temp->lchild)
            temp->bf--;
        else
            temp->bf++;
        if(temp->bf==0)
        {
            top=-1;
            break;
        }
        if(temp->bf==1||temp->bf==-1)
        {
            p=temp;
        }
        if(temp->bf==2||temp->bf==-2)
        {
            top=-1;//��ʼ��ջ��ָ��
            d=(temp->bf<0)?-1:1;
            if(p->bf==d)
            {
                if(d==-1)
                {
                    subrr(temp);
                }
                else
                {
                    subll(temp);
                }
            }
            else
            {
                if(d==-1)
                {
                    sublr(temp);
                }
                else
                    subrl(temp);
            }
            break;
        }
    }

}
void avl::subll(linknod* n)//���޸�����
{
    int tag=0,flag1=0;
    subl=n;
    n=subl->rchild;
    if(subl!=first)
        tag=1;
    subl->rchild=n->lchild;
    if(subl->rchild!=0)
    {
        subl->rchild->perint=subl;
        flag1=1;
    }
    n->lchild=subl;
    if(subl->perint!=0)
    {
        if(subl->perint->data>subl->data)
        {
            subl->perint->lchild=n;
        }
        else
        {
            subl->perint->rchild=n;
        }
        n->perint=subl->perint;
    }
    else
    {
        n->perint=0;
    }
    subl->perint=n;
    ptr=n;
    if(tag==1)
    {
        ptr=first;
        tag=0;
    }
    else
    {
        first=ptr;
        ptr->perint=0;
    }
    if(flag1==1)
    {
        subl->bf=1;
        n->bf=-1;
        flag1=0;
    }
    else
    {
        subl->bf=0;
        n->bf=0;
    }
}
void avl::subrr(linknod* n)//�޸�����
{
    int tag=0,flag1=0;
    subr=n;
    n=subr->lchild;
    if(subr!=first)
        tag=1;
    subr->lchild=n->rchild;
    if(subr->lchild!=0)
    {
        subr->lchild->perint=subr;
        flag1=1;
    }
    n->rchild=subr;
    if(subr->perint!=0)
    {
        if(subr->perint->data>subr->data)
        {
            subr->perint->lchild=n;
        }
        else
        {
            subr->perint->rchild=n;
        }
        n->perint=subr->perint;
    }
    else
    {
        n->perint=0;
    }
    subr->perint=n;
    ptr=n;
    if(tag==1)
    {
        ptr=first;
        tag=0;
    }
    else
    {
        first=ptr;
        ptr->perint=0;
    }
    if(flag1==1)
    {
        subr->bf=-1;
        n->bf=1;
        flag1=0;
    }
    else
    {
        n->bf=0;
        subr->bf=0;
    }
}
void avl::sublr(linknod* n)//���޸ĺ�
{
    int tag=0;
    subr=n;
    subl=subr->lchild;
    n=subl->rchild;
    if(subr!=first)
        tag=1;
    subl->rchild=n->lchild;
    if(subl->rchild!=0)
        subl->rchild->perint=subl;
    n->lchild=subl;
    subl->perint=n;
    if(n->bf<=0)
        subl->bf=0;
    else
        subl->bf=-1;
    subr->lchild=n->rchild;
    if(subr->lchild!=0)
        subr->lchild->perint=subr;
    n->rchild=subr;
    if(subr->perint!=0)
    {
        if(subr->perint->data<subr->data)
        {
            subr->perint->rchild=n;
        }
        else
        {
            subr->perint->lchild=n;
        }
        n->perint=subr->perint;
    }
    if(n->bf==-1)
        subr->bf=1;
    else
        subr->bf=0;
    subr->perint=n;
    ptr=n;
    if(tag==1)
    {
        ptr=first;
        tag=0;
    }
    else
    {
        first=ptr;
        ptr->perint=0;
    }
    n->bf=0;
}
void avl::subrl(linknod* n)//�޸ĺ�
{
    int tag=0;
    subl=n;
    subr=subl->rchild;
    n=subr->lchild;
    if(subl!=first)
        tag=1;
    subr->lchild=n->rchild;
    if(subr->lchild!=0)
        subr->lchild->perint=subr;
    n->rchild=subr;
    subr->perint=n;
    if(n->bf>=0)
        subr->bf=0;
    else
        subr->bf=1;
    subl->rchild=n->lchild;
    if(subl->rchild!=0)
        subl->rchild->perint=subl;
    n->lchild=subl;
    if(subl->perint!=0)
    {
        if(subl->perint->data<subl->data)
        {
            subl->perint->rchild=n;
        }
        else
        {
            subl->perint->lchild=n;
        }
        n->perint=subl->perint;
    }
    if(n->bf==1)
        subl->bf=-1;
    else
        subl->bf=0;
    subl->perint=n;
    ptr=n;
    if(tag==1)
    {
        ptr=first;
        tag=0;
    }
    else
    {
        first=ptr;
        ptr->perint=0;
    }
    n->bf=0;
}
int main()
{
    char select[100],slt;
    avl mm;
    int num[1000],m=0,n=0,n1=0,total=0,t=0,tag=0,ll=0,ll2=0,f=0;
    printf("1.����ƽ�������\n");
    printf("2.������\n");
    printf("3.ɾ�����\n");
    printf("4.���ҽ��\n");
    printf("5.��ʾ��ǰ��\n");
    printf("6.�˳�\n");
    printf("������Ҫִ�еĹ��ܴ���:\n");
    while(cin>>select)
    {
        if(!strcmp(select,"1"))
        {
            if(f==1)
            {
                cout<<"�Ѵ���һ������ȷ��Ҫ���½�����(y/n)"<<endl;
                cin>>slt;
                if(slt=='y'||slt=='Y')
                    f=0;
            }
            if(slt=='y'||slt=='Y'||f==0)
            {
                f=1;
                mm.ptr=0;
                cout<<"������Ҫ����ƽ��������Ľ�������";
                cin>>n;
                n=ll+n;
                cout<<"������Ҫ����ƽ��������Ľ��"<<endl;
                for(int i=0; i<n; i++)
                    cin>>num[i];
                for(int i=0; i<n; i++)
                {
                    if(mm.instalnod(num[i])==-1)
                    {
                        cout<<"��� "<<num[i]<<" �Ѵ��ڣ�����"<<endl;
                        n--;
                        continue;
                    }
                }
                cout<<"ǰ�����"<<endl;
                mm.display(mm.ptr);
                cout<<endl<<"�������"<<endl;
                mm.displaym(mm.ptr);
                cout<<endl;
                tag=0;
            }
        }
        else
        {
            if(!strcmp(select,"2"))
            {
                cout<<"������Ҫ����Ľ�������"<<endl;
                cin>>n1;
                //n1=112+n1;
                cout<<"������Ҫ����Ľ��"<<endl;
                for(int i=0; i<n1; i++)
                {
                    cin>>num[i];
                    mm.instalnod(num[i]);
                }
                cout<<"ǰ�����"<<endl;
                mm.display(mm.ptr);
                cout<<endl<<"�������"<<endl;
                mm.displaym(mm.ptr);
                cout<<endl;
                tag=0;
            }
            else
            {
                if(!strcmp(select,"3"))
                {
                    if(tag==0)
                    {
                        total=n+n1;
                        tag=1;
                    }
                    if(total==0)
                    {
                        cout<<"����Ϊ���������½�һ������"<<endl;
                    }
                    else
                    {
                        cout<<"������Ҫɾ���Ľ��ֵ:";
                        cin>>m;
                        t=mm.deletnod(m);
                        if(t==1)
                            total--;
                        else
                        {
                            cout<<"û��Ҫɾ���Ľ�㣡"<<endl;

                        }
                        if(total!=0)
                        {
                            cout<<"ǰ�����"<<endl;
                            mm.display(mm.ptr);
                            cout<<endl<<"�������"<<endl;
                            mm.displaym(mm.ptr);
                            cout<<endl;
                        }
                        else
                        {
                            cout<<"������ɾ��!"<<endl;
                            total=0;
                            n=0;
                            n1=0;
                            f=0;
                        }
                    }
                }
                else
                {
                    if(!strcmp(select,"4"))
                    {
                        cout<<"������Ҫ���ҵĽ�㣺" <<endl;
                        cin>>m;
                        if(mm.findnod(m,mm.ptr)==1)
                        {
                            cout<<"����Ҫ��Ľ��"<<m<<"!!"<<endl;
                        }
                        else
                        {
                            cout<<"���"<<m<<"������!!"<<endl;
                        }
                    }
                    else
                    {
                        if(!strcmp(select,"5"))
                        {
                            if(mm.ptr!=0)
                            {
                                cout<<"ǰ�����"<<endl;
                                mm.display(mm.ptr);
                                cout<<endl<<"�������"<<endl;
                                mm.displaym(mm.ptr);
                                cout<<endl;
                            }
                            else
                            {
                                cout<<"����Ϊ����!"<<endl;
                                f=0;
                            }
                        }
                        else if(!strcmp(select,"6"))
                            exit(1);
                    }
                }
            }
        }
        printf("1.����ƽ�������\n");
        printf("2.������\n");
        printf("3.ɾ�����\n");
        printf("4.���ҽ��\n");
        printf("5.��ʾ��ǰ��\n");
        printf("6.�˳�\n");
        printf("������Ҫִ�еĹ��ܴ���:\n");
    }
}
