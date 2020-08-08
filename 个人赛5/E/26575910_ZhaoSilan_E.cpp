#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using std::min;
using std::max;
const int N=2e5+10;
const int inf=0x3f3f3f3f;
#define ls ch[now][0]
#define rs ch[now][1]
int L[N*40],R[N*40],ch[N*40][2],tot;
int n,a[N],root;
void Insert(int &now,int x,int dep)
{
    if(!now) now=++tot;
    L[now]=min(L[now],x),R[now]=max(R[now],x);
    if(dep<0) return;
    int bit=a[x]>>dep&1;
    Insert(ch[now][bit],x,dep-1);
}
int query(int now,int val,int dep)
{
    if(dep<0) return 0;
    int bit=val>>dep&1;
    if(ch[now][bit]) return query(ch[now][bit],val,dep-1);
    else return query(ch[now][bit^1],val,dep-1)+(1<<dep);
}
ll dfs(int now,int dep)
{
    if(dep<0) return 0;
    if(R[ls]&&R[rs])
    {
        int mi=inf;
        for(int i=L[ls];i<=R[ls];i++) mi=min(mi,query(rs,a[i],dep-1));
        return dfs(ls,dep-1)+dfs(rs,dep-1)+mi+(1<<dep);
    }
    if(R[ls]) return dfs(ls,dep-1);
    if(R[rs]) return dfs(rs,dep-1);
    return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    std::sort(a+1,a+1+n);
    memset(L,0x3f,sizeof(L));
    for(int i=1;i<=n;i++) Insert(root,i,30);
    printf("%lld\n",dfs(root,30));
    return 0;
}
