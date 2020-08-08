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

char ch[1010][1010];
const int maxn=1e6+10;
pair<int,int> yi[maxn],er[maxn];


int main()
{
	int n,m;
	memset(ch,0,sizeof(ch));
	memset(yi,0,sizeof(yi));
	memset(er,0,sizeof(er));
	int k1(0),k2(0);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		getchar();
		for(int j=0;j<m;j++){
			scanf("%c",&ch[i][j]);
			if(ch[i][j]=='1'){
				yi[k1]=make_pair(i,j);
				k1++;
			}
			else if(ch[i][j]=='2'){
				er[k2]=make_pair(i,j);
				k2++;
			} 
		}
	}
	int _min=maxn;
	int x1,y1,x2,y2;
	for(int i=0;i<k2;i++){ 
		x2=er[i].first;y2=er[i].second;
		for(int j=0;j<k1;j++){
			x1=yi[j].first;y1=yi[j].second;
			_min=min(_min,abs(x1-x2)+abs(y1-y2)+1);
		}
	} 
	printf("%d",_min);
	return 0;
}