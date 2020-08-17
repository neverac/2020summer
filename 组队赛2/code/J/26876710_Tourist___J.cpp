#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[20][1000];
int ans;
int p[20];
void work(int w, int tot){
	if(ans != -1 && tot > ans) return;
	if(w == m + 1){
		for(int i = 1; i <= n; i++){
			int t = 0;
			for(int j = 1; j <= m; j++){
				if(p[j]) t |= (s[j][i] ^ 48);
			}
			if(t == 0) return;
		}
		ans = tot;
		return;
	}
	work(w + 1, tot);
	p[w] = 1;
	work(w + 1, tot + 1);
	p[w] = 0;
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++){
			scanf("%s", s[i] + 1);
		}
//		for(int i = 1; i <= m; i++){
//			for(int j = 1; j <= n; j++) putchar(s[i][j]);
//			puts("");
//		}
		ans = -1;
		work(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}