#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define maxn 1000010
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

bool vis[655360];
int ans[50];
int_ main(){
	int a;
	while(a=read()){
		int b=read(),c=read(),s=read();
		int mask=0;
		while(vis[s]==0){
			vis[s]=1;
			int qwq=s;
			s=(a*s+b)%c;
			mask|=qwq^s;
		}
		for(int i=0;i<=65536;++i) vis[i]=0;
		for(int i=1;i<=16;++i){
			ans[i]=(mask&1)?-1:(s&1);
			mask>>=1;
			s>>=1;
		}
		for(int i=16;i;i--){
			if(ans[i]==-1) printf("?");
			else printf("%d",ans[i]);
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