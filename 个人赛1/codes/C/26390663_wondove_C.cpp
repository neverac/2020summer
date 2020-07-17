#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define maxn 200010
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

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int ksm(int a,int b,int p){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret%p;
}
bool vis[maxn];
int a[maxn],ans[maxn];
int qwq[maxn];
int_ main(){
	int T=read();
	while(T--){
		bool flg=0;
		int n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=1;i<=n;++i) if(a[i]<i){
			puts("-1");
			flg=1;
			break;
		}
		if(flg==1) continue;
		for(int i=1;i<=n;++i){
			if(a[i]>a[i-1]) ans[i]=a[i],vis[a[i]]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(vis[i]==0) qwq[++cnt]=i;
		}
		cnt=1;
		for(int i=1;i<=n;++i){
			if(ans[i]==0) ans[i]=qwq[cnt++];
		}
		for(int i=1;i<=n;++i) printf("%d ",ans[i]);
		puts("");
		for(int i=1;i<=n;++i){
			ans[i]=0;
			vis[i]=0;
		}
		
	}
} 