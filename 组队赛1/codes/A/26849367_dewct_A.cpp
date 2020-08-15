#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long zu1[100];
    long long  zu2[100];
    memset(zu1,0,sizeof(zu1));
    string a;
    cin>>a;
    int k=1,k2=1;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i]>'9') zu1[k++]=10000000000+a[i];
        if(a[i]<='9')
        {
            int j=i;
            zu1[k]=(a[j]-'0');
            for(j=i+1; a[j]<='9'&&j<a.length(); j++)
            {
                zu1[k]=zu1[k]*10+(a[j]-'0');
            }
            k++;
            i=j;
            i--;
        }
    }
    while(n--)
    {
        k2=1;
        memset(zu2,0,sizeof(zu2));
        string b;
        cin>>b;
        for(int i=0; i<b.length(); i++)
        {
            if(b[i]>'9') zu2[k2++]=10000000000+b[i];
            if(b[i]<='9')
            {
                int j=i;
                zu2[k2]=(b[j]-'0');
                for(j=i+1; b[j]<='9'&&j<b.length(); j++)
                {
                    zu2[k2]=zu2[k2]*10+(b[j]-'0');
                }
                k2++;
                i=j;
                i--;
            }
        }
        int flag=1;
        for(int i=1;i<k&&i<k2;i++)
        {
            if(zu1[i]<zu2[i]) {cout<<"+"<<endl;flag=0;break;}
            if(zu1[i]>zu2[i]) {cout<<"-"<<endl;flag=0;break;}
            if(zu1[i]==zu2[i]) continue;
        }
        if(flag==1&&k==k2) cout<<"+"<<endl;
        if(flag==1&&k>k2) cout<<"-"<<endl;
        if(flag==1&&k<k2) cout<<"+"<<endl;
    }
    return 0;
}