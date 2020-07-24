#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

char s[1001000];
int f[1000100];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x;
		scanf("%d%d",&n,&x);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='0') f[i]=f[i-1]+1;
			else f[i]=f[i-1]-1;
		}
		bool flag=0;
		int ans=(x==0);
		for(int i=1;i<=n;i++){
			int A=f[i],B=f[n],C=x;
			if(B==0){
				if(C==A) flag=1;
			}
			else{
				if(C-A==0) ans++;
				if(1ll*(C-A)*B<=0) continue;
				if(((C-A)%B)==0&&((C-A)/B)>0) ans++;
			}
		}
		if(flag) printf("-1\n");
		else printf("%d\n", ans);
	}
}