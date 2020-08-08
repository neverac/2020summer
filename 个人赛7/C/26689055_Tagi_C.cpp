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
using namespace std;

int a[105],b[105];

int main()
{
	int n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	int _maxa(0),_maxb(0);
	int ja(0),jb(0);
	int x;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		a[i]=x;
		if(_maxa<x){
			_maxa=x;
			ja=i;
		}
	}
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		b[i]=x;
		if(_maxb<x){
			_maxb=x;
			jb=i;
		}
	}
	if(_maxa>_maxb){
		for(int i=0;i<n;i++){
			if(a[i]>_maxb){
				ja=i;
				break;
			}
		}
		printf("%d",n-ja);
		return 0;
	}
	else{
		for(int i=0;i<n;i++){
			if(b[i]>_maxa){
				jb=i;
				break;
			}
		}
		printf("%d",n-jb);
		return 0;
	}
	return 0;
}