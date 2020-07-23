#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 998244353;
const int SIZEN = 200010;
typedef long long LL;
LL N,K;
LL a[SIZEN] = {0}; 
LL sum[11] = {0};
LL pw10[SIZEN] = {0};
int nlen[SIZEN] = {0};
LL qpow(LL x,LL len){
	LL ret = 1;
	for(;len;len>>=1){
		if(len & 1)ret = ret * x % mod;
		x = x * x % mod;
	}
	return ret;
}
 
int main(){
	pw10[0] = 1;
	for(int i = 1;i < SIZEN;i++)pw10[i] = pw10[i-1] * 10 % mod;
	scanf("%lld",&N);
	for(int i = 1;i <= N;i++){
		int len = 0;
		scanf("%lld",&a[i]);
		LL tmp = a[i];
		while(tmp)len++,tmp/=10;
		sum[len]++;
		nlen[i] = len;
	}
	LL ans = 0;
	for(int i = 1;i <= N;i++){
		LL tmp = a[i];
		for(int j = 1;j <= nlen[i];j++){
			LL x = tmp % 10;
			tmp /= 10;
			for(int k = 1;k <= 10;k++){
				ans = (ans + x * pw10[j-1 + min(j-1,k)]*sum[k]%mod)%mod;
				ans = (ans + x * pw10[j-1 + min(j  ,k)]*sum[k]%mod)%mod;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
} 