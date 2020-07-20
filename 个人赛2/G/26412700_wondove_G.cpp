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
int ans[1000000];
int_ main(){
	int n=read(),k=read();
	ans[1]=1;
	for(int i=2;i<=k+1;++i){
		if(i%2==0) ans[i]=ans[i-1]+k-i+2;
		if(i%2==1) ans[i]=ans[i-1]-k+i-2;
	}
	for(int i=k+2;i<=n;++i){
		ans[i]=i;
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/