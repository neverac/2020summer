#include<bits/stdc++.h>
using namespace std;
int n, m, vis[100010], ans[100010];
void solve(){
	int cur = 1;
	ans[++ans[0]] = cur;
	vis[cur] = 1;
	for(int i = m; i >= 1; i--){
		if(cur - i >= 1 && !vis[cur - i]) cur -= i;
		else cur += i;
		ans[++ans[0]] = cur;
		vis[cur] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]) ans[++ans[0]] = i;
	}
	printf("%d", ans[1]);
	for(int i = 2; i <= n; i++) printf(" %d", ans[i]);
	return ;
}
int main(){
	cin>>n>>m;
	solve();
	return 0;
}
