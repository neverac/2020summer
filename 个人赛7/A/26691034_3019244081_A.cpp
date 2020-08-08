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

int pos[30][N];
int cnt[30];
char s[N];
int main(){
	for(int i=0;i<=26;i++){
		pos[i][0]=0;
		for(int j=1;j<=1e5;j++) pos[i][j]=-1;
	}
	int k;
	scanf("%d",&k);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		int x=s[i]-'a';
		cnt[x]++;
		pos[x][cnt[x]]=i;
	}
	ll ans=0;
	for(int i=0;i<26;i++){
		int now=0;
		for(int j=1;j<=len;j++){
			if(s[j]=='a'+i){
				now++;
			}
			if(now==0) continue;
			else if(now<=k) ans+=pos[i][now];
			else ans+=pos[i][now]-pos[i][now-k];
		}
	}
	printf("%lld",ans);
	return 0;
}