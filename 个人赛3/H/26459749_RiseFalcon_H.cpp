#include <cstdio>
#include <cstring>
//#include <algorithm>
//using namespace std;
const int MAXN=60+10;
typedef long long LL;
const LL mod=998244353;
char w[MAXN][MAXN];
LL input() {
	LL x;
	scanf("%lld",&x);
	return x;
}
int doing() {
	int n=input();
	int m=input();
	for(int i=1;i<=n;++i) {
		scanf("%s",w[i]+1);
	}
	
	
	{
		bool have=false;
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				if(w[i][j]=='A') {
					have=true;
				}
			}
		}
		if(have==false) {
			printf("MORTAL\n");
			return 0;
		}	
	}
	int ans=4;
	
	
	
	for(int i=1;i<=n;++i) {
		if(w[i][1]=='A') ans=3;
		if(w[i][m]=='A') ans=3;
	}
	for(int j=1;j<=m;++j) {
		if(w[1][j]=='A') ans=3;
		if(w[n][j]=='A') ans=3;
	}
	
	
	if(w[1][m]=='A'||w[n][m]=='A' || w[1][1]=='A' ||w[n][1]=='A') ans=2;
	for(int i=1;i<=n;++i) {
		bool is=true;
		for(int j=1;j<=m;++j) {
			if(w[i][j]!='A') {
				is=false;
				break;
			}
		}
		if(is)ans=2;
	}
	for(int j=1;j<=m;++j) {
		bool is=true;
		for(int i=1;i<=n;++i) {
			if(w[i][j]!='A') {
				is=false;
				break;
			}
		}
		if(is)ans=2;
	}
	
	
	{
		bool is=true;
		for(int j=1;j<=m;++j) {
			if(w[1][j]!='A') {
				is=false;
				break;
			}
		}
		if(is) ans=1;
	}
	{
		bool is=true;
		for(int j=1;j<=m;++j) {
			if(w[n][j]!='A') {
				is=false;
				break;
			}
		}
		if(is) ans=1;
	}
	{
		bool is=true;
		for(int i=1;i<=n;++i) {
			if(w[i][1]!='A') {
				is=false;
				break;
			}
		}
		if(is) ans=1;
	}
	{
		bool is=true;
		for(int i=1;i<=n;++i) {
			if(w[i][m]!='A') {
				is=false;
				break;
			}
		}
		if(is) ans=1;
	}
	
	{
		bool have=false;
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				if(w[i][j]=='P') {
					have=true;
				}
			}
		}if(!have)ans=0;
	}
	printf("%d\n",ans);
	return 0;
}
int main() {
	int t=input();
	for(int i=1;i<=t;++i) {
		doing();
	}
	return 0;
} 