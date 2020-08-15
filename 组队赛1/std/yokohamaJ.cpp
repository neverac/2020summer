#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef double db;
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
#define low(x) ((x)&-(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define X first
#define Y second
const int N=1e6+10;
const ll mod=1e9+7;
template<typename T> inline T gcd(T a,T b){return !b?a:gcd(b,a%b);}
template<typename T> inline T q_pow(T a,T x){T ans=1,tmp=a;while(x){if(x&1)(ans*=tmp)%=mod;(tmp*=tmp)%=mod;x>>=1;}return ans;}
template<typename T> inline void re(T &N){int f=1;char c;while((c=getchar())< '0'||c> '9')if(c=='-')f=-1;N=c-'0';while((c=getchar())>='0'&&c<='9')N=N*10+c-'0';N*=f;}
int m,n,t=1,st,en,Max;
vector<int>edges[N];
int dep[N],siz[N],dfn[N],rdfn[N];
namespace HLD{
    int tot,rt=1;
    int son[N],top[N],fa[N];
    void dfs(int u,int p)
    {
        fa[u]=p;
        dep[u]=dep[p]+1;
        siz[u]=1;son[u]=0;
        int ma=-1;
        for(auto& v:edges[u])
        {
            if(v==p)continue;
            dfs(v,u);siz[u]+=siz[v];
            if(siz[v]> ma)ma=siz[v],son[u]=v;
        }
    }
    void dfs(int u,int p,int tp)
    {
        dfn[u]=++tot,rdfn[tot]=u;
        top[u]=tp;
        if(son[u])dfs(son[u],u,tp);
        for(auto& v:edges[u])
        {
            if(v==p||v==son[u])continue;
            dfs(v,u,v);
        }
    }
    void build()
    {
        tot=0;
        dfs(rt,0);
        dfs(rt,0,rt);
    }
    int lca(int x,int y)
    {
        while(top[x]!=top[y])
        {
            if(dep[top[x]]< dep[top[y]])swap(x,y);
            x=fa[top[x]];
        }
        if(dep[x]> dep[y])swap(x,y);
        return x;
    }
}
using HLD::lca;
vector<int>init_col[N];
set<int>col[N];
int c[N];
ll ans[N];
inline int calc(int x,int y,int color,int op)
{
    x=rdfn[x];y=rdfn[y];
    int l=lca(x,y);
    ans[color]+=op*(dep[x]+dep[y]-2*dep[l]);
}
int main()
{
    re(n);
    for(int i=1;i< n;i++)
    {
        int x,y;
        re(x);re(y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    HLD::build();
    for(int i=1;i<=n;i++)
    {
        re(c[i]);Max=max(Max,c[i]);
        init_col[c[i]].push_back(i);
    }
    for(int i=1;i<=Max;i++)if(init_col[i].size())
    {
        for(int j:init_col[i])col[i].insert(dfn[j]);
        for(auto it1=col[i].begin(),it2=++col[i].begin();it2!=col[i].end();it1++,it2++)
        {
            calc(*it1,*it2,i,1);
        }
        calc(*col[i].begin(),*col[i].rbegin(),i,1);
    }
    re(m);
    for(int i=1;i<=m;i++)
    {
        char s[2];
        int x,y;
        scanf("%s",s);
        if(s[0]=='U')
        {
            re(x);re(y);
            if(col[c[x]].size()==1||col[c[x]].size()==2)col[c[x]].erase(dfn[x]),ans[c[x]]=0;
            else 
            {
                auto pre=col[c[x]].lower_bound(dfn[x]);
                if(pre==col[c[x]].begin())pre=--col[c[x]].end();
                else pre--;
                auto aft=col[c[x]].upper_bound(dfn[x]);
                if(aft==col[c[x]].end())aft=col[c[x]].begin();
                calc(*pre,dfn[x],c[x],-1);
                calc(*aft,dfn[x],c[x],-1);
                calc(*pre,*aft,c[x],1);
                col[c[x]].erase(dfn[x]);
            }
            c[x]=y;
            if(col[c[x]].size()==0)col[c[x]].insert(dfn[x]);
            else if(col[c[x]].size()==1)
            {
                int elem=*col[c[x]].begin();
                calc(dfn[x],elem,c[x],2);
                col[c[x]].insert(dfn[x]);
            }
            else
            {
                auto pre=col[c[x]].lower_bound(dfn[x]);
                if(pre==col[c[x]].begin())pre=--col[c[x]].end();
                else pre--;
                auto aft=col[c[x]].upper_bound(dfn[x]);
                if(aft==col[c[x]].end())aft=col[c[x]].begin();
                calc(*pre,*aft,c[x],-1);
                calc(*pre,dfn[x],c[x],1);
                calc(*aft,dfn[x],c[x],1);
                col[c[x]].insert(dfn[x]);
            }
        }
        else 
        {
            re(x);
            if(col[x].empty())puts("-1");
            else printf("%lld\n",ans[x]/2);
        }
    }
}
