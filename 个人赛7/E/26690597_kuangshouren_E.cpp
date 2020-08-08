#include<iostream>
using namespace std;
long long n,m;
long long a[20];
long long ans;
long long gcd(long long x,long long y)
{
	if(y==0)return x;
	else return gcd(y,x%y);
}
void dfs(int p,int h,long long x)
{
	if(x>n)return;
	if(p==m+1)
	{
		if(h!=0)
		{
			if(h%2==1)
			{
				ans+=n/x;
			}
			else
			{
				ans-=n/x;
			}
		}
		return;
	}
	dfs(p+1,h,x);
	dfs(p+1,h+1,x/gcd(x,a[p])*a[p]);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)cin>>a[i];
	dfs(1,0,1);
	cout<<ans;
	return 0;
}