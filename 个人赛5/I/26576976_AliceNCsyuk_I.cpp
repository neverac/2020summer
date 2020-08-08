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
#include<queue>
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
#define maxn 100000
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
int t;
queue<int> q1;
queue<int> q2;
string s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		while(!q1.empty())
		{
			q1.pop();
		}
		while(!q2.empty())
		{
			q2.pop();
		}
		for(int i=0;i<s.length();i++)
		{
			int num=s[i]-'0';
			if(num%2==0)
			{
				q1.push(num);
			}
			else
			{
				q2.push(num);
			}
		}
		while(!q1.empty()&&!q2.empty())
		{
			if(q1.front()<q2.front())
			{
				cout<<q1.front();
				q1.pop();
			}
			else
			{
				cout<<q2.front();
				q2.pop();
			}
		}
		while(!q1.empty())
		{
			cout<<q1.front();
			q1.pop();
		}
		while(!q2.empty())
		{
			cout<<q2.front();
			q2.pop();
		}
		cout<<endl;
	}
	return 0;
}