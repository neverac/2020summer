#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
char str[1000010];
const int mod = 4;
int qpow(int x,int len){
	int ret = 1;
	for(;len;len>>=1){
		if(len & 1)ret = ret * x % 5;
		x =  x* x % 5;
	}
	return ret;
}
int main(){
	scanf("%s",str+1);
	int n = strlen(str+1);
	int ans = 0;
	int mi = 0;
	for(int i = 1;i <= n;i++){
		mi = mi * 10 + str[i] - '0';
		mi = mi % mod;
	}
	mi += mod;//printf("mi = %d\n",mi);
	for(int i = 1;i <= 4;i++)ans = ans + qpow(i,mi);
	printf("%d\n",ans%5);
	return 0;
} 