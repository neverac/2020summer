#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define ll long long
#define maxn 2000010
const int Mod=(1ll<<61)-1;
const int inf=1e9+7;
inline int read(){
	int ret=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') ff=-ff;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*ff;
}
char str[maxn],ans[maxn],bns[maxn];
int_ main(){
	int T=read();
	while(T--){
		scanf("%s",str+1);
		int qwq=0,qaq=0;
		int n=strlen(str+1);
		for(int i=1;i<=n;++i){
			if(str[i]&1) ans[++qwq]=str[i];
			else bns[++qaq]=str[i];
		}
		int i=1,j=1;
		while(i<=qwq&&j<=qaq){
			if(ans[i]<bns[j]){
				printf("%c",ans[i]);
				++i;
			}
			else{
				printf("%c",bns[j]);
				++j;
			}
		}
		while(i<=qwq){
			printf("%c",ans[i]);
				++i;
		}
		while(j<=qaq){
			printf("%c",bns[j]);
				++j;
		}
		puts("");
	}
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/