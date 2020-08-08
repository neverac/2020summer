#include<bits/stdc++.h>
using namespace std;
#define MAXN 200010
int N,a[MAXN];
#define LL long long
LL sum[MAXN];
int main(){
	int T; cin>>T;
	while (T--){
		scanf("%d",&N);
		for (int i=1; i<=N; i++) scanf("%d",&a[i]),sum[i] = sum[i-1]+a[i];
		LL mn = 0;
		int flag = 1,p = 0;
		for (int i=1; i<N; i++){
			if (sum[i]-mn >= sum[N]){
				flag =0;
				break;
			}
			if (mn >= sum[i]){
				mn = sum[i];
				p = i;
			}
//			mn = min(mn, sum[i]);
		}
		if (p!=0 && sum[N]-mn >= sum[N]) flag = 0;
//		for (int i=1; i<=N; i++) printf("%I64d   ",sum[i]);
		if (flag) puts("YES"); else puts("NO");
	}
	return 0;
}