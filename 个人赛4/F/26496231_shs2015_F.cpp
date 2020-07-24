#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int main(){
	int k,n,s,p;
	scanf("%d%d%d%d",&k,&n,&s,&p);
	LL one = n / s + (n % s != 0);
	one = one * k;
	LL t = one / p + (one % p != 0);
	printf("%lld\n",t);

} 