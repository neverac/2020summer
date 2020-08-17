#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<stdio.h>
#define ll long long
#define maxn 2001
using namespace std;
template <class T>
bool read(T &x)
{
    char c;
    bool op=0;
    while(c=getchar(),c<'0'||c>'9')
	if(c=='-')
	{
		op=1;
	}
	else if(c==EOF)
	{
		return 0;
	} 
    x=c-'0';
    while(c=getchar(),c>='0'&&c<='9')
	x=x*10+c-'0';
    if(op)x=-x;
    return 1;
}
template <class T>
void write(T x)
{
    if(x>=10)
	{
		write(x/10);
	}
    putchar('0'+x%10);
}
ll t;
ll k;
ll L;
ll n;
ll exgcd(ll a,ll b,ll &x,ll &y)//ax+by=gcd(a,b)的解 
{
	int d=a;
	if(b!=0)
	{
		d=exgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else
	{
		x=1;
		y=0;
	}
	return d;//gcd(a,b) 
}
int main()
{
	read(t);
	while(t--)
	{
		read(k),read(L);
		if(L>=2000)
		{
			cout<<-1<<endl;
			continue;
		}
		n=1999;
		write(n);
		cout<<endl;
		for(int i=0;i<n-2;i++)
		{
			cout<<0<<" ";
		}
		cout<<k%1998-1998<<" "<<(k-1999*(k%1998-1998))/1998<<endl;
	}
	return 0;
}