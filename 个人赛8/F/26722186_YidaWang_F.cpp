#include<bits/stdc++.h>
using namespace std;
int N,a[200010],cnt[10];
char s[200010];
int main(){
	int T; cin>>T;
	while (T--){ 
		scanf("%s",s+1);
		N = strlen(s+1);
		for (int i=1; i<=N; i++) a[i] = s[i]-'0';
		int ans = N;
		for (int x=0; x<=9; x++){
			int cnt = 0;
			for (int i=1; i<=N; i++) if (a[i]==x) cnt++;
			ans = min(N-cnt,ans);
		}
		for (int x=0; x<=9; x++){
			for (int y=0; y<=9; y++){
				if (x==y) continue;
				int op=1,cnt=0;
				for (int i=1; i<=N; i++){
					if (op){
						if (a[i] == x) cnt++,op^=1; 
					} else {
						if (a[i] == y) cnt++,op^=1;
					}
				}
				if (cnt&1) cnt--;
				ans = min(N-cnt,ans);
			}
		}
		printf("%d\n",ans); 
	}
	return 0;
}