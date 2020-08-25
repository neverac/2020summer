#include<bits/stdc++.h>
using namespace std;
struct Node{
	int cnt[10],x;
}st[300];
bool cmp(Node a,Node b){
	for (int i=9; i>=0; i--){
		if (a.cnt[i] == b.cnt[i]) continue;
		return a.cnt[i]>b.cnt[i];
	}
	return a.x>b.x;
}
int num[20],tot;
int main(){
	int T; cin>>T;
	while (T--){
		int sum = 0;
		for (int i=0; i<=9; i++){
			scanf("%d",&num[i]);
			sum += num[i];
		}
		if (sum == 1){
			int ans = -1; 
			for (int i=0; i<=9; i++){
				if (num[i] && i%4==0) ans = i;
			}
			printf("%d\n",ans);
			continue;
		}
		if (sum == 2){
			int ans = -1;
			for (int i=0; i<=9; i++){
				if (!num[i]) continue;
				for (int j=0; j<=9; j++){
					if (!num[j] || (i==j&&num[i]==1)) continue;
					int x = i*10+j;
					if (x%4==0) ans = max(ans,x);
				}
			}
			if (ans == -1){
				for (int i=0; i<=9; i++){
					if (num[i] && i%4==0) ans = max(ans,i);
				}
			}
			printf("%d\n",ans);
			continue;
		}
		tot = 0;
		for (int i=0; i<=9; i++){
			if(!num[i]) continue;
			for (int j=0; j<=9; j++){
				if (!num[j] ||(i==j && num[i]==1)) continue;
				int x = i*10+j;
				if (x%4==0){
					num[i]--; num[j]--;
					st[++tot].x = x;
					for (int k=0; k<=9; k++) st[tot].cnt[k] = num[k];
					num[i]++; num[j]++;
				}
			} 
		}
		if (!tot) {
			int ans = -1;
			for (int i=0; i<=9; i++) if (num[i] && i%4==0) ans = max(ans,i);			
			printf("%d\n",ans);
			continue;
		}
		if (sum == num[0]){
			puts("0");
			continue;
		}		
		sort(st+1,st+tot+1,cmp);
		for (int i=9; i>=0; i--){
			for (int j=st[1].cnt[i]; j; j--)
				printf("%d",i);
		}
		if (st[1].x < 10) printf("0%d\n",st[1].x);
		else printf("%d\n",st[1].x); 
	}
	return 0;
}