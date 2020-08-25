#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long int n,m,x,y;
        scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
        if(x<=y)
        {
            printf("%lld\n",m);
            continue;
        }
        long long int ans=(n-y)/(x-y);
        
        if(ans>=m)
        {
            printf("%lld\n",m);
            continue;
        }
        ans+=((m-ans)*y+(n-y)%(x-y))/x;
        printf("%lld\n",ans);
    }
    return 0;
}
