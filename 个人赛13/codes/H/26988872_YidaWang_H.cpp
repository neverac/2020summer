#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL rt[600],ct[600],a[600][600];
int N,M,K; 
const int MOD = 998244353;
int main(){
	scanf("%d%d%d",&N,&M,&K);
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			scanf("%lld",&a[i][j]);
			a[i][j] %= MOD;
		}
	}
	for (int i=1; i<=K; i++){
		char s[10]; 
		int p; LL t;
		scanf("%s%d%lld",s+1,&p,&t);
		if (s[1]=='r') rt[p] = max(rt[p],t);
		else ct[p] = max(ct[p],t);
	}
	LL ans = 0;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			ans += max(rt[i],ct[j])%MOD * a[i][j] %MOD;
			ans %= MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
}