#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int SIZEN = 200010;
typedef long long LL;
#define mid ((l+r) >> 1)
int N,M;
LL a[SIZEN];
priority_queue<LL> q;
LL ans = 0;
void work(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		scanf("%lld",&a[i]);
		q.push(-a[i]);
	}
	LL ans = 0;
	while(!q.empty()){
		LL x = q.top();q.pop();
		if(q.empty())break;
		LL y = q.top();q.pop();
		ans += x+y;
		q.push(x+y);
	}
	printf("%lld\n",-ans);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
4
6
2 3 4 4 5 7
5
5 15 40 30 10
10
3 1 5 4 8 2 6 1 1 2
9
3 2 1 6 5 2 6 4 3
*/