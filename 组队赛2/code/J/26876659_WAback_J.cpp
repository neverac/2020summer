#include<bits/stdc++.h>
using namespace std;
int ans,vis[550],N,M;
char s[30][550];
void dfs(int dep,int cnt){
	if (dep == M+1){
		for (int i=1; i<=N; i++) if (!vis[i]) return;
//		puts("debug");
//		for (int i=1; i<=N; i++) printf("%d  ",vis[i]); puts("");
		ans = min(ans, cnt);
		return;
	}
	dfs(dep+1,cnt);
	for (int i=1; i<=N; i++) if (s[dep][i] == '1') vis[i]++;
	dfs(dep+1,cnt+1);
	for (int i=1; i<=N; i++) if (s[dep][i] == '1') vis[i]--;
}
int main(){
	int T; cin>>T;
	while (T--){
		scanf("%d%d",&N,&M);
		for (int i=1; i<=M; i++) scanf("%s",s[i]+1);
		ans = M+1;
		for (int i=1; i<=N; i++) vis[i] = 0;
		dfs(1,0);
		if (ans > M) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}
/*
1
5 6
10000
01001
01110
00111
10110
00101
*/