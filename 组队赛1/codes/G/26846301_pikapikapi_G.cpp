#include<bits/stdc++.h>
#define lowbit(a) ((a)&-(a))
using namespace std;

struct node
{
    int x,pos;
}a[100005];
int n;
int c[100005],c1[100005];
bool cmp(node a,node b)
{
    return a.x>b.x;
}


void add(int x)
{
    for(int i=x;i<=n;i+=lowbit(i))
        c[i] += 1;
}

int sum(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i))
        ans += c[i];
    return ans;
}

void add2(int x)
{
    for(int i=x;i<=n;i+=lowbit(i))
        c1[i] += 1;
}
int sum2(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i))
        ans += c1[i];
    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].x);
        a[i].pos=i;
    }
    sort(a+1,a+1+n,cmp);
    int ks=1;//从最大的开始判断
    long long int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].x!=a[i-1].x)
        {
            for(int j=ks;j<i;j++)//一样的一起处理
            {
                add(a[j].pos);
                add2(n+1-a[j].pos);
            }
            ks=i;//
        }
        ans+=min(sum(a[i].pos),sum2(n+1-a[i].pos));
    }
    printf("%lld\n",ans);
    return 0;
    
}
