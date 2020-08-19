#include<iostream>
#include<cmath>
using namespace std;
int a[500];
int f[507];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	f[0]=1;
	int ans=360;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			int sum=0;
			if(i<=j)
			{
				for(int k=i;k<=j;++k)sum+=a[k];
			}
			else
			{
				for(int k=i;k<=n;++k)sum+=a[k];
				for(int k=1;k<=j;++k)sum+=a[k];
			}
			ans=min(ans,abs(sum-(360-sum)));
		}
	}
	cout<<ans;
	return 0;
}