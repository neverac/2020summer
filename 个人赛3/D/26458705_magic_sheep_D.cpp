#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 4e5+100;

bool vis[maxn];
int n,a[maxn],prime[maxn];
int T1,T2,m,cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) T1++,m++;
		else T2++,m+=2;
	}
	for(int i=2;i<=m;i++)
	{
		if(!vis[i])
		{
			int cur = i;
			prime[++cnt] = i;
			while(cur<=m)
			{
				vis[cur] = true;
				cur+=i;
			}
		}
	}
	int st = 0,cur = 1;
	for(int i=1;i<=n;i++)
	{
		if(prime[cur]==0) break;
 		if(st+2<=prime[cur]&&T2) T2--,cout<<2<<" ",st+=2;
		else
		{
			if(T1) T1--,cout<<1<<" ",st++;
			else T2--,cout<<2<<" ",st+=2;
		}
		if(st==prime[cur]) cur++;
		//cout<<st<<" "<<prime[cur]<<endl;
	}
	while(T1--) cout<<1<<" ";
	while(T2--) cout<<2<<" ";
	cout<<endl;
	return 0;
}