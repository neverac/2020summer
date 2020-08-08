#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

int n,m;
LL mod;

LL ph(LL x)
{
	LL res = x,a=x;
	for(LL i=2;i*i<=x;i++)
	{
		if(a%i==0)
		{
			res = res/i*(i-1);
			while(a%i==0) a/=i;
		}
	}
	if(a>1) res = res/a*(a-1);
	return res;
}

LL Pow(LL a,LL b,LL p)
{
	LL res = 1;
	while(b)
	{
		if(b&1) res=res*a%p;
		b >>=1;
		a = a*a%p;
	}
	return res;
}

LL work(LL x,LL p)
{
	if(x==1) return 1%p;
	if(x==2) return 2%p;
	if(x==3) return 9%p;
	if(x==4) return (1<<18)%p;
	if(p==1) return 0;
	LL k = ph(p);
	//cout<<k<<" "<<p<<endl;
	return Pow(x,work(x-1,k)+k,p);
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cout<<work(n,m)<<endl;
	return 0;
}