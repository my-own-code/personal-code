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
    if(bucket[key] == a)	//直接找到
    {
        number = 1;
        return key;
    }
    else  //否则继续探测
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
    //没有找到
    number = -200;
    return -1;
}
int main()
{
    for(int i=0; i<200; i++)
    {
        bucket[i] = "";
    }
    /*随机生成TESTSIEZ个字符串，长度为20，测试填充因子和平均查找次数*/
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
    cout<<"已经随机生成"<<150<<"个字符串！"<<endl;
    time_t start,end;
    start = clock();
    for(int i=0; i<testlist.size(); i++)
    {
        cout<<testlist[i]<<" : "<<insert(testlist[i])<<endl;
    }
    end = clock();
    cout<<"插入150个字符串时间为："<<(double)((double)(end-start)/1000)<<" s"<<endl;
    double average_number = 0;
    int findnumber = 0;
    for(int i=0; i<testlist.size(); i++)
    {
        find(testlist[i],findnumber);
        average_number += findnumber;
    }
    average_number /= testlist.size();
    cout<<"采用闭散列法，平均查找次数为："<<average_number<<endl;
    return 0;
}
