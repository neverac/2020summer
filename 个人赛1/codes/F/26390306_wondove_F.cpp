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
int a[maxn],num[maxn];
int_ main(){
	memset(num,0,sizeof(num));
	int n=read();
	int ans=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		ans+=a[i];
		++num[a[i]];
	}
	
	int q=read();
	while(q--){
	//	printf("ans=%d\n",ans);
		int x=read(),y=read();
		ans+=(y-x)*num[x];
		num[y]+=num[x];
		num[x]=0;
		printf("%lld\n",ans);
	}
	return 0;
} 