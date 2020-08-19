#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
#define maxn 100001 
#define elenum 2//元素个数 
#define num 4000000//要开n*max(str(s))，其中n为字符串数目，后面为最长字符串长度，开越大越好，但是开太大可能因为初始化而超时 
using namespace std;
int tire[num][elenum];//字典树 
bool endnode[num];//是否为终结节点 
int create_new_node=1;//字典树节点数目 
void Insert(const string &s)
{
	int len=s.length();
	int now=0;
	int ele;
	for(int i=0;i<len;i++)
	{
		ele=s[i]-'0';
		if(!tire[now][ele])
		{
			tire[now][ele]=create_new_node++;
	    }
		now=tire[now][ele];
	}
	endnode[now]=true;
}
bool Search(const string &s)
{
	int len=s.length();
	int now=0;//当前节点 
	int ele;
	for(int i=0;i<len;i++)
	{
		ele=s[i]-'0';
		if(!tire[now][ele])
		{
			return false;
		}
		now=tire[now][ele];
	}
	return endnode[now];
}
void init()
{
	memset(tire,0,sizeof(tire));
	memset(endnode,0,sizeof(endnode));
}
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
ll llmin(ll a,ll b)
{
	if(a<=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
ll n;
ll arr[maxn];
ll ans;
ll num2[31];
void getbits(ll a,string& bits)//一个数转换为二进制字符串 
{
    bits="";
    ll loc=0;
    while(a)
    {
        ll tmpnum=a%2;
        a/=2;
        bits+=(tmpnum+'0');
    }
    ll len=bits.length();
    for(int i=0;i<30-len;i++)
    {
    	bits+="0";
	}
	reverse(bits.begin(),bits.end());
}
ll dfs(ll len,ll x)
{
	if(len<0)
	{
		return 0;
	}
	else
	{
		if(tire[x][0]&&tire[x][1])
		{
			return num2[len]+llmin(dfs(len-1,tire[x][0]),dfs(len-1,tire[x][1]));
		}
		else if(tire[x][0])
		{
			return dfs(len-1,tire[x][0]);
		}
		else
		{
			return dfs(len-1,tire[x][1]);
		}
	}
}
int main()
{
	read(n);
	init();
	for(int i=0;i<n;i++)
	{
		read(arr[i]);
		string tmps;
		getbits(arr[i],tmps);
		Insert(tmps);
	}
	ll x=1;
	for(int i=0;i<31;i++)
	{
		num2[i]=x;
		x*=2;
	}
	ans=dfs(30,0);
	ans/=2;
	write(ans);
	printf("\n");
	return 0;
}