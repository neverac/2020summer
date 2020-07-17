#include <bits/stdc++.h>
using namespace std;
int a[100010];
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--){
		int temp = 1;
		bool vis[100010];
		memset(vis,false,sizeof(vis));
		scanf("%d",&n);
		for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
		bool flag = true;
		for(int i = 1; i <= n; ++i){
			 if(a[i] < i) {flag = false;break;}
		}
		if(!flag) {printf("-1\n");continue;}
		printf("%d",a[1]);
		vis[a[1]] = true;
		for(int i = 2; i <= n; ++i) 
		  if(a[i] == a[i-1]){
		  	while(vis[temp]) ++temp;
		  	printf(" %d",temp++);
		  } 
		  else{
		  	printf(" %d",a[i]);
		  	vis[a[i]] = true;
		  }
		printf("\n");
	}
	return 0;  
} 