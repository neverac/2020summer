#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZEN = 200010;
typedef long long LL;
#define mid ((l+r) >> 1)
int N,M;
int a[SIZEN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		LL a = 1LL*N*(N+1) ^ (N+1);
		printf("%lld\n",a);
	}
	return 0;
}
/*
3
6
7
10
*/