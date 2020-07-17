#include<cstdio>
#include<iostream>
#define maxn 100005
#define ll long long 
using namespace std;
ll n,q,a[maxn],sum;
int tm[maxn];
int main(void)
{
    while(~scanf("%lld",&n))
    {
        sum=0;
        for(int i=0;i<n;++i)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];//求和
            tm[a[i]]++;//a[i]出现的次数自增
        }
        scanf("%lld",&q);
        ll b,c;
        for(int i=0;i<q;++i)
        {
            scanf("%lld %lld",&b,&c);
            sum+=(c-b)*tm[b];
            tm[c]+=tm[b];//更新tm[c]
            tm[b]=0;//更新tm[b]
            printf("%lld\n",sum);
        }
    }
    return 0;
}
