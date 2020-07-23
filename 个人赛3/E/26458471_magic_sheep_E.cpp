#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5+100;

int n;
long long a[maxn],b[maxn],f[maxn][2],mx1,mx2;


int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	mx1 = a[1];
	mx2 = b[1];
	f[1][0] = a[1];
	f[1][1] = b[1];
	for(int i=2;i<=n;i++)
	{
		f[i][0] = mx2 +a[i];
		f[i][1] = mx1 +b[i];
		mx1 = max(mx1,f[i][0]);
		mx2 = max(mx2,f[i][1]);
	}
	cout<<max(mx1,mx2)<<endl;
	return 0;
}