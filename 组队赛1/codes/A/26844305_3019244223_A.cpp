#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<string.h>
#include<time.h>
#include<queue>
#include<stack>
#include<map>
#include<cctype>
using namespace std;
#define ll  long long
#define ull unsigned long long
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}

struct qwq
{
    
};
bool cmp(qwq q,qwq w)
{
    
}


long long x1[100];
long long  x2[100];
int main()
{
    int n;
    cin>>n;
    memset(x1,0,sizeof(x1));
    string a;
    cin>>a;
    int k=1,k2=1;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i]>'9') x1[k++]=10000000000+a[i];
        if(a[i]>='0' && a[i]<='9')
        {
            int j=i;
            x1[k]=(a[j]-'0');
            for(j=i+1; a[j]<='9'&&j<a.length(); j++)
            {
                x1[k]=x1[k]*10+(a[j]-'0');
            }
            k++;
            i=j;
            i--;
        }
    }
    while(n--)
    {
        k2=1;
        memset(x2,0,sizeof(x2));
        string b;
        cin>>b;
        for(int i=0; i<b.length(); i++)
        {
            if(b[i]>'9') x2[k2++]=10000000000+b[i];
            if(b[i]<='9')
            {
                int j=i;
                x2[k2]=(b[j]-'0');
                for(j=i+1; b[j]<='9'&&j<b.length(); j++)
                {
                    x2[k2]=x2[k2]*10+(b[j]-'0');
                }
                k2++;
                i=j;
                i--;
            }
        }
        int flag=1;
        for(int i=1;i<k&&i<k2;i++)
        {
            if(x1[i]<x2[i])
            {
                cout<<"+"<<endl;
                flag=0;
                break;
            }
            if(x1[i]>x2[i]) 
            {
                cout<<"-"<<endl;
                flag=0;
                break;
            }
            if(x1[i]==x2[i]) 
                continue;
        }
        if(flag==1&&k>k2) 
            cout<<"-"<<endl;
        if(flag==1&&k<=k2) 
            cout<<"+"<<endl;
    }

    //system("pause");
    return 0;
}