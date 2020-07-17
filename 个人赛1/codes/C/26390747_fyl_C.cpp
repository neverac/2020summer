#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int a[100010],vis[100010],s[100010];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof a);
		memset(vis,0,sizeof vis);
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(int i=1;i<=n;i++){
			if(s[i]!=s[i-1])
				a[i]=s[i],vis[s[i]]=1;
		}
		int j=1,flag=0;
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
			if(a[i]) continue;
			while(j<=n&&vis[j]) j++;
			mx=max(mx,j);
			if(mx!=s[i]){flag=1;break;}
			a[i]=j;
			vis[j]=1;
		}
		if(flag){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}puts("");
	}
}	
/*
4
5
1 3 4 5 5
4
1 1 3 4
2
2 2
1
1
*/