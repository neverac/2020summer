#include<iostream>
#include<cstdio>
using namespace std;
long long ans=0;
void gcd(long long x,long long y)
{
	if(y==0)
	{
		return;
	}
	ans+=x/y;
	gcd(y,x%y);
}
int main()
{
	long long x,y;
	cin>>x>>y;
	gcd(x,y);
	cout<<ans;
	return 0;
}