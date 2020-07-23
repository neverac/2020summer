#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 5000+100;

int n,m,x,y,X[maxn],Y[maxn];

stack<int> S;
vector<int> f[maxn];

int low[maxn],pre[maxn],scc[maxn],cnt,dfs_clock,ans[maxn];
void dfs(int u)
{
    pre[u]=low[u]=dfs_clock++;
    S.push(u);
    for(int i=0;i<f[u].size();i++)
    {
        int v=f[u][i];
        if(!pre[v])
        {
            dfs(v);
            low[u]=min(low[v],low[u]);
        }
        else if(!scc[v])
        {
            low[u]=min(low[u],pre[v]);
        }
    }
    if(low[u]==pre[u])
    {
        cnt++;
        for(;;)
        {
            int x=S.top();
            S.pop();
            scc[x]=cnt;
            if(x==u) break;
        }
    }
}
void find_scc(int n)
{
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++)
    {
        if(!pre[i]) dfs(i);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		f[x].push_back(y);
		X[i] = x;
		Y[i] = y;
	}
	find_scc(n);
	if(cnt<n) cout<<"2"<<endl;
	else cout<<"1"<<endl;
	if(cnt<n)
	{
		for(int i=1;i<=m;i++)
		{
			if(X[i]<Y[i]) cout<<1<<" ";
			else cout<<2<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(int i=1;i<=m;i++) cout<<1<<" ";
			cout<<endl;
	}
	return 0;
}