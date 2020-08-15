#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N];
long long ans,cnt;
int times[N],L[N],R[N];

int ask(int x)
{
    int ret=0;
    for(int i=x;i;i-=(i&(-i)))
        ret+=times[i];
    return ret;
}

void add(int x,int d)
{
    for(int i=x;i<=N;i+=(i&(-i)))
        times[i]+=d;
    return ;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        L[i]=i-1-ask(a[i]);
        add(a[i],1);
    }
    memset(times,0,sizeof(times));
    for(int i=n;i>=1;i--)
    {
        R[i]=n-i-ask(a[i]);
        add(a[i],1);
    }
    for(int i=1;i<=n;i++)
        ans+=(long long)min(L[i],R[i]);
    printf("%lld\n",ans);
    return 0;
}