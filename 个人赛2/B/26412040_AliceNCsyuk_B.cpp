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
#define maxn 100000
using namespace std;
bool used[maxn];
int a,b,c,s;
char tmpans[16];
char ans[16];
bool flag;
int main()
{
	while(scanf("%d",&a))
	{
		if(a==0)
		{
			break;
		}
		scanf("%d%d%d",&b,&c,&s);
		memset(used,false,sizeof(used));
		for(int i=0;i<16;i++)
		{
			tmpans[i]=ans[i]='0';
		}
		flag=true;
		while(used[s]==false)
		{
			used[s]=true;
			int tmps=s;
			int loc=15;
			while(tmps>0)
			{
				if(flag)
				{
					if(tmps%2==0)
					{
						ans[loc]=tmpans[loc]='0';
					}
					else
					{
						ans[loc]=tmpans[loc]='1';
					}
					loc--;
					tmps/=2;
				}
				else
				{
					if(tmps%2==0)
					{
						if(tmpans[loc]!='0')
						{
							ans[loc]='?';
						}
					}
					else
					{
						if(tmpans[loc]!='1')
						{
							ans[loc]='?';
						}
					}
					loc--;
					tmps/=2;
				}
			}
			flag=false;
			s=((a*s)%c+b%c)%c;
		}
		for(int i=0;i<16;i++)
		{
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}