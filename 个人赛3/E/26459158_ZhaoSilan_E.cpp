#include<stdio.h>
#include<iostream>
using namespace std;
long long int f[10];
long long int a[100005],b[100005];
long long int max(long long int x,long long int y)
{
    return x>y?x:y;
}
int main()
{
    int n;
    scanf("%d",&n);
    f[1]=0;
    f[2]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&b[i]);
    }
    for(int i=0;i<n;i++)
    {
        long long int x=max(f[1],f[2]+a[i]);
        long long int y=max(f[2],f[1]+b[i]);
        f[1]=x;
        f[2]=y;
    }
    printf("%lld\n",max(f[1],f[2]));
    return 0;
}