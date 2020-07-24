#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5+100;

int gcd(int x,int y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}
int T,a,n,b,cnt;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>a>>b;
		int gd = gcd(a,b);
		if(n/gd%2==1)
		{
			cout<<"Case #"<<++cnt<<": "<<"Yuwgna"<<endl;
		}
		else 
			cout<<"Case #"<<++cnt<<": "<<"Iaka"<<endl;
	}
	return 0;
}