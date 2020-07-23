#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define maxn 1000010
const int inf=1e9+7;
inline int read(){
	int ret=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') ff=-ff;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*ff;
}
int a[maxn];
int b[maxn],dp[maxn][4];
char str[maxn];
int_ main(){
	int n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	for(int i=1;i<=n+1;++i){
		dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i];
		dp[i][2]=max(dp[i-1][1],dp[i-1][0])+b[i];
	}
	printf("%lld\n",dp[n+1][0]);
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/