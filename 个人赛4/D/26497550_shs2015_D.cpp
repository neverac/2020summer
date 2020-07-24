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
int gcd(int x,int y){
	if(y == 0)return x;
	return gcd(y,x%y);
}
int main(){
	int t;scanf("%d",&t);
	for(int i = 1;i <= t;i++){
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		int total = n / gcd(a,b) - 2;
		if(total % 2 == 0)printf("Case #%d: Iaka\n",i);
		else printf("Case #%d: Yuwgna\n",i);
	}
	return 0;
} 