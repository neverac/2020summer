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
int ksm(int a,int b,int p){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret%p;
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
inline int phi(int n)
{
	int ans=n;
	for(int i=2;i<=sqrt(n);++i){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}
int cal(int n,int m){
	if(m==1) return 0;
	if(n==1) return 1;
	if(n==2) return 2%m;
	if(n==3) return 9%m;
	if(n==4) return 262144%m;
	int ppp=cal(n-1,phi(m))+phi(m);
	return ksm(n,ppp,m);
}
int_ main(){
		int n=read(),m=read();
		printf("%lld\n",cal(n,m));
//	}
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/