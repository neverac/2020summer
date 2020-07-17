#include<iostream>
#include<algorithm>
using namespace std;
int n,k;int a[1007];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=k;++i)ans+=a[i];
	cout<<ans;
	return 0;
}