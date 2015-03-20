#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
string  bucket[200];

int hash(string a)
{
    int key = 0;
    for(int i=0; i<a.size(); i++)
    {
        key =key + a[i];
    }
    key = key%200;
    return key;
}
int insert(string a)
{
    int key = hash(a);
    if(bucket[key]=="")
    {
        bucket[key] = a;
    }
    else
    {
        key = (key+1)%200;
        while(bucket[key]!="")
        {
            key = (key+1)%200;
        }
        bucket[key] = a;
    }
    return key;
}
int find(string a,int &number)
{
    int key = hash(a);
    if(bucket[key] == a)	//ֱ���ҵ�
    {
        number = 1;
        return key;
    }
    else  //�������̽��
    {
        number = 1;
        key = (key+1)%200;
        while(bucket[key]!=a)
        {
            key = (key+1)%200;
            number ++;
        }
        return key;
    }
    //û���ҵ�
    number = -200;
    return -1;
}
int main()
{
    for(int i=0; i<200; i++)
    {
        bucket[i] = "";
    }
    /*�������TESTSIEZ���ַ���������Ϊ20������������Ӻ�ƽ�����Ҵ���*/
    srand(time(NULL));
    vector<string>  testlist;
    testlist.clear();
    for(int i =0; i<150; i++)
    {
        string a="";
        for(int j=0; j<20; j++)
        {
            a += 'A'+rand()%26;
        }
        testlist.push_back(a);
    }
    cout<<"�Ѿ��������"<<150<<"���ַ�����"<<endl;
    time_t start,end;
    start = clock();
    for(int i=0; i<testlist.size(); i++)
    {
        cout<<testlist[i]<<" : "<<insert(testlist[i])<<endl;
    }
    end = clock();
    cout<<"����150���ַ���ʱ��Ϊ��"<<(double)((double)(end-start)/1000)<<" s"<<endl;
    double average_number = 0;
    int findnumber = 0;
    for(int i=0; i<testlist.size(); i++)
    {
        find(testlist[i],findnumber);
        average_number += findnumber;
    }
    average_number /= testlist.size();
    cout<<"���ñ�ɢ�з���ƽ�����Ҵ���Ϊ��"<<average_number<<endl;
    return 0;
}
