#include<iostream>
using namespace std;
int n;long long f[100007][2],a[100007][2];
long long maxn;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i][0]);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i][1]);
	f[0][0]=0;f[0][1]=0;
	f[1][0]=a[1][0];f[1][1]=a[1][1];
	for(int i=2;i<=n;++i)
	{
		f[i][0]=max(f[i-2][1],f[i-1][1]);
		f[i][0]+=a[i][0];
		f[i][1]=max(f[i-1][0],f[i-2][0]);
		f[i][1]+=a[i][1];
	}
	cout<<max(f[n][0],f[n][1]);
	return 0;
} 