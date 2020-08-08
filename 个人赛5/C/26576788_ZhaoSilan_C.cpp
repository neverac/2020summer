#include<stdio.h>
#include<iostream>
using namespace std;
long long int ans[400];
long long int m[400];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&m[i]);
   
    for(int i=1;i<n;i++)
    {
        if(m[i]<=m[i+1])
        {
            ans[i]=1;
        }
        else
        {
            ans[i]=0;
        }
    }
    long long int a=0;
    long long int b=100;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==1&&ans[i-1]==0)
        {
            if(b>=m[i])
            {
                a=b/m[i];
                if(a>=1e5)
                a=1e5;
            b=b-m[i]*a;
            }
        }
        else  if(ans[i]==0&&ans[i-1]==1)
        {
            b=b+a*m[i];
            a=0;
        }
    }
    printf("%lld\n",b);
    return 0;
}