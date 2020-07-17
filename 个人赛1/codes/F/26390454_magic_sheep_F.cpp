#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5+100;

int n,k,T,m;
long long x,y,a[maxn],mp[maxn],ans[maxn];
long long sum =0;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=n;i++) mp[a[i]]++,sum+=a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		//cout<<mp[x]<<" "<<mp[y]<<endl;
		mp[y]+=mp[x];
		sum-=(mp[x]*x);
		sum+=(y*mp[x]);
		mp[x] = 0;
		cout<<sum<<endl;
	}
	return 0;
}