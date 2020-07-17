#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5+100;

int n,k,T;
int a[maxn],vis[maxn],ans[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) vis[i] = 0;
		int cnt = 0,l=1;
		int ok = 1; 
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i-1]) ans[i] = a[i],vis[a[i]]=1;
			else
			{
				while(vis[l]) l++;
				ans[i] = l;
				vis[l] = 1;
				if(l>n||l>a[i]) ok = 0;
			}
		}
		if(!ok) cout<<-1<<endl;
		else
		{
			for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
				cout<<endl;
		}
	}
	return 0;
}