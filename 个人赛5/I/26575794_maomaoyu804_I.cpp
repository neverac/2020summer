#include <bits/stdc++.h>
using namespace std;

int a0[300005],a1[300005];
int ans[300005];
char s[300005];

int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		int p0=0,p1=0;
		for(int i=0;i<len;i++){
			if((s[i]-'0')&1) a1[p1++]=s[i]-'0';
			else a0[p0++]=s[i]-'0'; 
		}
		int p00=0,p11=0;
		int p=0;
		while(p00<p0&&p11<p1){
			if(a0[p00]<a1[p11]) ans[p++]=a0[p00++];
			else ans[p++]=a1[p11++];
		}
		while(p00<p0) ans[p++]=a0[p00++];
		while(p11<p1) ans[p++]=a1[p11++];
		for(int i=0;i<p;i++) printf("%d",ans[i]);
		puts("");
	}
	return 0;
}