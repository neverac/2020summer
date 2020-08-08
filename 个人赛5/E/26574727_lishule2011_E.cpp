#include<bits/stdc++.h>
using namespace std;
#define ll long long
//sss
const int N=2e5+5;
int tr[N*32][2],p[N*32],cnt=1,a[N];
vector<int>vec[N];
void add(int s,int id)
{
    int now=1;
    for(int i=30;i>=0;i--)
    {
        int &ne=tr[now][((s>>i)&1)];
        if(!ne)
            ne=++cnt;
        now=ne;
    }
    p[now]=id,vec[id].push_back(a[id]);
}
int finds(int root,int s,int dep)
{
    int now=root;
    int ans=0;
    for(int i=dep-1;i>=0;i--)
    {
        int ne=tr[now][((s>>i)&1)];
        if(!ne)
            ans|=(1<<i),ne=tr[now][(1^((s>>i)&1))];
        now=ne;
    }
    return ans|(1<<dep);
}
ll ans;
void dfs(int x,int dep)
{
    if(!x||!dep)
        return ;
    int ls=tr[x][0],rs=tr[x][1];
    dfs(ls,dep-1),dfs(rs,dep-1);
    if(!ls||!rs)
    {
        p[x]=p[ls+rs];
        return ;
    }
    int lid=p[ls],rid=p[rs];
    if(vec[rid].size()>vec[lid].size())
        swap(ls,rs),swap(lid,rid);
    int mi=2e9;
    for(int i=0;i<vec[rid].size();i++)
    {
        mi=min(mi,finds(ls,vec[rid][i],dep-1));
        vec[lid].push_back(vec[rid][i]);
    }
    vec[rid].clear();
    p[x]=p[ls];
    ans+=(ll)mi;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        if(a[i]!=a[i-1])
            add(a[i],i);
    dfs(1,31);
    printf("%lld\n",ans);
    return 0;
}

