#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef int int_;

#define int long long
#define maxn 2000010
const int Mod=998244353;
const int inf=1e9+7;
const int p=998244353;
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
int p3[maxn],p33[maxn],p5[maxn],p55[maxn],p7[maxn],p77[maxn];
int_ main(){
	int T=read();
	int N=1000000000000000ll;
	p3[0]=p33[0]=p5[0]=p55[0]=p7[0]=p77[0]=1;
	for(int i=1;p3[i-1]<=N;++i) p3[i]=p3[i-1]*3ll,p33[i]=p33[i-1]+p3[i];
	for(int i=1;p5[i-1]<=N;++i) p5[i]=p5[i-1]*5ll,p55[i]=p55[i-1]+p5[i];
	for(int i=1;p7[i-1]<=N;++i) p7[i]=p7[i-1]*7ll,p77[i]=p77[i-1]+p7[i];
	while(T--){
		int n=read();
		while((n&1ll)==0) n>>=1ll;
		int c3=0,c5=0,c7=0;
		while(n%3==0){
			++c3;
			n/=3ll;
		}
		while(n%5ll==0){
			++c5;
			n/=5ll;
		}
		while(n%7ll==0){
			++c7;
			n/=7ll;
		}
		//printf("%d %d %d\n",c3,c5,c7);
		printf("%lld\n",p33[c3]*p55[c5]*p77[c7]);
	}
	return 0;
} 