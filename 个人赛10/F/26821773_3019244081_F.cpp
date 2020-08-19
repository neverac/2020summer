#include<bits/stdc++.h>
/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime> 
*/
#define ll long long
using namespace std; 
const int N=1e5 + 100;
const double eps=1e-10;
int ch[30*N][3];
int num=0;
void ins(int x){
	int now=0;
	for(int i=30;i>=0;i--){
		bool f=(1<<i)&x;
		//printf("%d ",f);
		if(!ch[now][f]){
			ch[now][f]=++num;
			ch[num][0]=0;
			ch[num][1]=0;
		}
		now=ch[now][f];
	}
}
int dfs(int now,int dep){
	if(!ch[now][0] && !ch[now][1]) return 0;
	if(!ch[now][0]) return dfs(ch[now][1],dep-1);
	if(!ch[now][1]) return dfs(ch[now][0],dep-1);
	return (1<<dep)+min(dfs(ch[now][0],dep-1),dfs(ch[now][1],dep-1));
}
int main(){
	int n;
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		ins(x);//printf("???");
	}
	printf("%d",dfs(0,30));
	return 0;
}