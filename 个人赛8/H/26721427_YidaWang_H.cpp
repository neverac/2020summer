#include<bits/stdc++.h>
using namespace std;
int N,a[200010],f[200010],g[200010];
int main(){
	scanf("%d",&N);
	for (int i=1; i<=N; i++) scanf("%d",&a[i]);
	f[1] = 1;
	for (int i=2; i<=N; i++){
		if (a[i] > a[i-1]) f[i] = f[i-1]+1;
		else f[i] = 1;
	}
	g[N] = 1;
	for (int i=N-1; i>=1; i--){
		if (a[i] < a[i+1]) g[i] = g[i+1]+1;
		else g[i] = 1;
	}
	int ans = 0;
	for (int i=1; i<=N; i++){
		if (a[i-1] < a[i+1]) ans = max(ans, f[i-1]+g[i+1]);
		else ans = max(ans, max(f[i],g[i]));
	}
	printf("%d\n",ans);
	return 0;
}