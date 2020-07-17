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
int a[maxn],b[maxn];
int_ main(){
	int n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=m;++i) b[i]=read();
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	if(b[1]<a[n]){
		puts("-1");
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=a[i];
	}
	ans*=m;
	for(int i=2;i<=m;++i) ans+=b[i]-a[n];
	if(a[n]!=b[1]) ans+=b[1]-a[n-1];
	printf("%lld\n",ans);
} 