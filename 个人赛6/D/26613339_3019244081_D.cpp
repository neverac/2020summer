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

//ll dp[150][150];
//ll mp[150][150];
ll cnt[150][150][20];
int main(){
	int n,q,c,x,y,s;
	scanf("%d%d%d",&n,&q,&c);
	memset(cnt,0,sizeof(cnt));
	 /*for(int i=0;i<=100;i++){
	 	dp[i][0]=0;
	 	dp[0][i]=0;
	 }*/
	 for(int i=1;i<=n;i++){
	 	scanf("%d%d%d",&x,&y,&s);
	 	cnt[x][y][s]++;
	 	//mp[x][y]=s;
	 }
	 for(int i=1;i<=100;i++){
	 	for(int j=1;j<=100;j++){
		 	//dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mp[i][j];
		 	for(int k=0;k<=c;k++){
				cnt[i][j][k]+=cnt[i-1][j][k]+cnt[i][j-1][k]-cnt[i-1][j-1][k];
			 }
		 }
	 }
	 
	 /*for(int i=1;i<=10;i++){
	 	for(int j=1;j<=10;j++){
		 	printf("%d ",cnt[i][j][2]);
		 }
		 cout<<endl;
	 }*/
	 ll ans=0;
	 int t,x2,y2;
	 for(int i=1;i<=q;i++){
	 	scanf("%d%d%d%d%d",&t,&x,&y,&x2,&y2);
	 	ans=0;
	 	//ans=dp[x2][y2]+dp[x-1][y-1]-dp[x-1][y2]-dp[x2][y-1];
	 	//printf("??%lld??",ans);
		 for(ll k=0;k<=c;k++){
		 	ll xx=(k+t)%(c+1);
		 	ans+=xx*(cnt[x2][y2][k]+cnt[x-1][y-1][k]-cnt[x-1][y2][k]-cnt[x2][y-1][k]);
		 }
		 printf("%lld\n",ans);
	 }
	return 0;
}