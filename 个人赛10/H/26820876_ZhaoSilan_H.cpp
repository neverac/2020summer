#include<stdio.h>
#include<iostream>
using namespace std;
int a[370];
bool f[370];
int sum[370];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            if(sum[j]-sum[i-1]<=180)
            {
                ans=max(sum[j]-sum[i-1],ans);
            }
            else
            {
                ans=max(360-sum[j]+sum[i-1],ans);
            }
        }
    
    printf("%d\n",(180-ans)*2);
//    f[0]=1;
//    for(int i=1;i<=n;i++)
//        for(int j=180;j>=a[i];j--)
//        {
//            f[j]=f[j]|f[j-a[i]];
//        }
//
//    for(int i=180;i>=0;i--)
//    {
//        if(f[i])
//        {
//            printf("%d\n",2*(180-i));
//            break;
//        }
//    }
    return 0;
}