#include <bits/stdc++.h>
using namespace std;
int const maxn=1e5+7;
typedef long long ll;
int n;
long long dp[2][maxn],h[2][maxn];
inline int get_num(){
    char ch;
    int num=0;
    ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
    return num;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		h[0][i]=get_num();
	}
	for(int i=1;i<=n;i++){
		h[1][i]=get_num();
	}
	dp[0][1]=h[0][1];
	dp[1][1]=h[1][1];
	if(n>1){
		dp[0][2]=h[0][2]+dp[1][1];
		dp[1][2]=h[1][2]+dp[0][1];
	}
	for(int i=3;i<=n;i++){
		dp[0][i]=max(dp[1][i-1],dp[1][i-2])+h[0][i] ;
		dp[1][i]=max(dp[0][i-1],dp[0][i-2])+h[1][i];
	}
	long long ans=max(dp[0][n],dp[1][n]);
	printf("%lld\n",ans);
	return 0;
}