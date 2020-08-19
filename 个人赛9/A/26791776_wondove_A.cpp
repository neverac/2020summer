#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define maxn 2000010
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
int a[1000010];
int_ main(){
	int n=read();
	for(int i=1;i<=n<<1;++i){
		a[i]=read();
	}
	sort(a+1,a+1+(n<<1));
	int ans=(a[n]-a[1])*(a[n<<1]-a[n+1]);
	for(int i=1;i<=n;++i){
		ans=min(ans,(a[n<<1]-a[1])*(a[n+i]-a[i+1]));
	}
	printf("%lld\n",ans);
	return 0;
} 