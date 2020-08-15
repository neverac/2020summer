#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
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

const int maxn=2*500*500+5;

int a[maxn];
int vis[maxn];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	int r,s,p;
	scanf("%d%d%d",&r,&s,&p);
	int i,j;
	memset(vis,0,sizeof(vis));
	for(int k=1;k<=p;k++){
		scanf("%d%d",&i,&j);
		
		a[k]=r+1-i+(j<s+1?s+1-j:j-s);
	}
	sort(a+1,a+1+p,cmp);
//	for(int i=0;i<=p;i++)cout<<a[i]<<" ";cout<<endl;
	int step=0;
	for(int k=1;k<=p;k++){
		int t=a[k];
		if(t>0){
			step+=t;
			vis[k]=1;
			int ii=k+1;
			for(ii=k+1;ii<=p&&t>0;ii++){
				if(!vis[ii])t--;
				a[ii]-=t;
				vis[ii]=1;
			}
//			for(int i=0;i<=p;i++)cout<<a[i]<<" ";cout<<endl;
		}
	}
	printf("%d",step);
}