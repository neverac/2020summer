#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
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
#define LL long long
#define ULL unsigned long long
using namespace std;

LL ppow(LL a,LL b)
{
	LL res(1);
	for(int i=0;i<b;i++)res*=a;
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	LL a;
	LL ans(0);
	LL div(0);
	while(n--){
		ans=0;
		scanf("%lld",&a);
		while(a%2==0)a/=2;
		
//		while(div<)
		
		div=3;
		int num3(0),num5(0),num7(0);
		while(a%div==0){
			num3++;
			div*=3;
		}
		div=5;
		while(a%div==0){
			num5++;
			div*=5;
		}
		div=7;
		while(a%div==0){
			num7++;
			div*=7;
		}
		
		LL aa=3*(ppow(3,num3)-1)/2;
		LL bb=5*(ppow(5,num5)-1)/4;
		LL cc=7*(ppow(7,num7)-1)/6;
		ans+=(aa+1)*(bb+1)*(cc+1);
		printf("%lld\n",ans);
	}
}