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
int Phi(int x){
	int ans=x;
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			ans-=ans/i;
			while(x%i==0) x/=i;
		}
		
	}
	if(x!=1) ans-=ans/x;
	return ans;
}
int_ main(){
	int T=read();
	while(T--){
		int a=read(),m=read();
		int x=gcd(a,m);
		//printf("x=%d\n",x);
		printf("%lld\n",Phi(m/x));
	} 
	return 0;
} 