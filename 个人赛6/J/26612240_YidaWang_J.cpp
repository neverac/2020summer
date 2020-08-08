#include<bits/stdc++.h>
using namespace std;
int N,K;
int w[100010];
int main(){
	scanf("%d%d",&N,&K);
	for (int i=1; i<=N; i++) scanf("%d",&w[i]);
	int ans = 0;
	for (int i=1; i<=N; i++){
		ans += (w[i]/K) + (w[i]%K !=0? 1:0);
	}
	printf("%d\n",ans/2 + (ans%2 !=0 ? 1:0));
	return 0;
}