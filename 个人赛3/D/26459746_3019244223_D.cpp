#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<set>
using namespace std;
int x[5]={0};
int res[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        if(a==1)
            x[1]++;
        else
            x[2]++;
    }
    int pos=1;
    if(x[2])
    {
        res[1]=2;
        pos++;
        x[2]--;
        if(x[1]>0)
        {

            res[2]=1;
            pos++;
            x[1]--;
        }
    }
    for(int i=1;i<=x[2];++i)
    {
        res[pos]=2;
        pos++;
    }
    for(int i=1;i<=x[1];++i)
    {
        res[pos]=1;
        pos++;
    }
    for(int i=1;i<pos;++i)
        cout<<res[i]<<" ";

    
    


    //system("pause");
    return 0;
}