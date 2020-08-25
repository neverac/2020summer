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
#define maxn 501
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
ll n,m,k;
ll graph[maxn][maxn];
ll c[maxn];
ll r[maxn];
char ch;
ll ans;
ll mo=998244353;
ll llmax(ll a,ll b)
{
	if(a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int main()
{
	read(n),read(m),read(k);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			read(graph[i][j]);
		}
	}
	for(int i=0;i<k;i++)
	{
		ll tmpn,tmpt;
		cin>>ch>>tmpn>>tmpt;
		if(ch=='r')
		{
			r[tmpn-1]=tmpt;
		}
		else
		{
			c[tmpn-1]=tmpt;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ans+=(graph[i][j]%mo*(llmax(r[i],c[j])%mo));
			ans%=mo;
		}
	}
	write(ans);
	cout<<endl;
	return 0;
}