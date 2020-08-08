#include<stdio.h>
#include<iostream>
using namespace std;
int x[200005];
int f[200005],ff[200005];
int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    int n;
    scanf("%d",&n);
    f[0]=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        if(x[i]>x[i-1])
            f[i]=f[i-1]+1;
        else
            f[i]=1;
        ans=max(ans,f[i]);
    }
    
    ff[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        if(x[i]<x[i+1])
        {
            ff[i]=ff[i+1]+1;
        }
        else
            ff[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(x[i+1]>x[i-1])
            ans=max(ans,f[i-1]+ff[i+1]);
//        printf("%d %lld %d %d\n",i,ans,f[i-1],ff[i+1]);
    }
    printf("%d\n",ans);
    return 0;
}
