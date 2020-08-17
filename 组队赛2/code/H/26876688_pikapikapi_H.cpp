#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long int n;
        scanf("%lld",&n);
        long long int m=n+1e7;
        long long int ans=0;
        for(long long int i=n+1;i<=m;i++)
        {
            if(n*i%(i-n)==0)
            {
                long long int a=(n*i/(i-n))^i;
                ans=max(ans,a);
            }
            else
                continue;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
