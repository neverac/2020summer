#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int SIZEN = 500010;
int N;
map<long long ,int> mp;
int main(){
	scanf("%d",&N);
	long long ans = 0;
	for(int i = 1;i <= N;i++){
		long long x;
		scanf("%lld",&x);
		mp[x]++;
		ans += x;
	}
	int M;
	scanf("%d",&M);
	for(int i = 1;i <= M;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		ans -= x * mp[x];
		ans += y * mp[x];
		mp[y] += mp[x];
		mp[x] = 0;printf("%lld\n",ans);
	}
	
	return 0;
}
/*
4
1 1 1 1
3
1 2
2 1
3 5
*/