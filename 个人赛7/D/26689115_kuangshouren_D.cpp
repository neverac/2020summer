#include<iostream>
#include<cstdio>
using namespace std;
long long f[107];
int T;
int main()
{
	cin>>T;
	for(int w=1;w<=T;++w)
	{
		long long n;
		scanf("%lld",&n);
		while(n%2==0)n/=2;
		long long g=1;
		f[3]=1;
		while(n%3==0)
		{
			n/=3;
			g*=3;
			f[3]+=g;
		}
		g=1;
		f[5]=1;
		while(n%5==0)
		{
			n/=5;
			g*=5;
			f[5]+=g;
		}
		g=1;
		f[7]=1;
		while(n%7==0)
		{
			n/=7;
			g*=7;
			f[7]+=g;
		}
		printf("%lld\n",f[3]*f[5]*f[7]);
	}
	return 0;
}