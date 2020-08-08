/**
 *　　　　　　　　┏┓　　 　┏┓
 * 　　　　　　　┏┛┗━━━━━━━┛┗━━━┓
 * 　　　　　　　┃　　　　　　　┃ 　
 * 　　　　　　　┃　　　━　　 　┃
 * 　　　　　　　┃　＞　　　＜　┃
 * 　　　　　　　┃　　　　　　　┃
 * 　　　　　　　┃...　⌒　... 　┃
 * 　　　　　　　┃　　　　　　　┃
 * 　　　　　　　┗━┓　　　┏━┛
 * 　　　　　　　　　┃　　　┃　Code is far away from bug with the animal protecting　　　　　　　　　　
 * 　　　　　　　　　┃　　　┃   神兽保佑,代码无bug
 * 　　　　　　　　　┃　　　┃　　　　　　　　　　　
 * 　　　　　　　　　┃　　　┃  　　　　　　
 * 　　　　　　　　　┃　　　┃
 * 　　　　　　　　　┃　　　┃　　　　　　　　　　　
 * 　　　　　　　　　┃　　　┗━━━┓
 * 　　　　　　　　　┃　　　　　　　┣┓
 * 　　　　　　　　　┃　　　　　　　┏┛
 * 　　　　　　　　　┗┓┓┏━┳┓┏┛
 * 　　　　　　　　　　┃┫┫　┃┫┫
 * 　　　　　　　　　　┗┻┛　┗┻┛
 */ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<bitset>
#include<stdlib.h>
#include<assert.h>
#include<string>
#include<iomanip> 
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

//const int maxn=1e5;
//struct node{
//	int x,y,brit;
//}star[maxn];

int  main()
{
	int n,q,c;
	scanf("%d%d%d",&n,&q,&c);
	int xi,yi,init;
//	memset(vis,0,sizeof(vis));
	int star[102][102][12]={0};
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&xi,&yi,&init);
		star[xi][yi][init]++;
	}
	int xi1,yi1,xi2,yi2,days;
	int aum(0);
	
	for(int k=0;k<=c;k++){
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++)
				star[i][j][k]+=star[i][j-1][k];
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++)
				star[i][j][k]+=star[i-1][j][k];
	}
	
	for(int k=0;k<q;k++){
		aum=0;
		scanf("%d%d%d%d%d",&days,&xi1,&yi1,&xi2,&yi2);
//		for(int i=x1i;i<=x2i;i++){
//			for(int j=y1i;j<=y2i;j++){
//				for(int jj=0;jj<=10;jj++){
//					if(star[i][j][jj]>0)
//					aum+=star[i][j][jj]*((jj+days)%(c+1));
//				}
////				if(vis[i][j]==1){
////					aum+=(star[i][j]+days)%(c+1); 
////				}
//			}
//		}
		for(int j=0;j<=c;j++){
			aum+=((j+days)%(c+1))*(star[xi2][yi2][j]-star[xi2][yi1-1][j]-star[xi1-1][yi2][j]+star[xi1-1][yi1-1][j]);
		}
		printf("%d\n",aum);
	}
	return 0;
	
}