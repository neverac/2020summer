#include<bits/stdc++.h>
using namespace std;
int a[100010],n,x;
char s[100010];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&x);
		scanf("%s",s+1);
		int cnt0=0,cnt1=0;
		for (int i=1; i<=n; i++){
			if (s[i]-'0') cnt1++;
			else cnt0++;
			a[i] = cnt0-cnt1;
		}
		int p = a[n];
		int ans = 0;
		if (x==0) ans++;
//		puts("debug");
//		for (int i=1; i<=n; i++) printf("%d  ",a[i]); puts("");
		if (!p){
			for (int i=1; i<=n; i++) if (a[i]==x) ans++;
			if (ans) puts("-1");
			else puts("0");
			continue;
		}
		for (int i=1; i<=n; i++){
			int d = x-a[i];
			if (!d) ans++; else {
				if (1LL*d*p>0) ans += (d%p==0? 1:0);
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}