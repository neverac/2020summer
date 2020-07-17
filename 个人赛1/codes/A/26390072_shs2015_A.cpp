#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100010] = {0};
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= N;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+N);
	long long ans = 0;
	for(int i = 1;i <= M;i++)ans += a[i];
	printf("%lld\n",ans);
}
