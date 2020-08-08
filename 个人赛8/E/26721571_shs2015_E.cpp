#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int SIZEN = 200010;
int N;
typedef long long LL;
LL a[SIZEN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i = 1;i <= N;i++){
			scanf("%lld",&a[i]);
			a[i] += a[i-1];
		}
		LL mn = 0;
		LL ans = -0x3f3f3f3f3f3f3f3fLL;
		for(int i = 1;i < N;i++){
			ans = max(ans,a[i] - mn);
			mn = min(mn,a[i]);
		}
		for(int i = 1;i < N;i++)ans = max(ans,a[N]-a[i]);
		if(a[N] > ans)puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
3
4
1 2 3 4
3
7 4 -1
3
5 -5 5
*/