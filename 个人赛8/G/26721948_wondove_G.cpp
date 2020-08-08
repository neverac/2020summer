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
int qwq[maxn];
int Abs(int x){
	if(x<0) x=-x;
	return x;
}
int x[1000],y[100010];
int_ main(){
	x[1]=read(),y[1]=read();
	int ax=read(),ay=read(),bx=read(),by=read();
	int sx=read(),sy=read(),t=read();
	int cnt=1;
	while(Abs(x[cnt]-sx)<=2e16&&Abs(y[cnt]-sy)<=2e16){
		++cnt;
		x[cnt]=x[cnt-1]*ax+bx;
		y[cnt]=y[cnt-1]*ay+by;
	}
//	for(int i=1;i<=cnt;++i){
//		printf("%lld %lld\n",x[i],y[i]);
//	}
	int ans=0;
	for(int i=1;i<=cnt;++i){
		for(int j=1;j<=cnt;++j){
			int dis=Abs(x[i]-x[j])+Abs(y[i]-y[j]);
			dis+=Abs(sx-x[i])+Abs(sy-y[i]);
			//printf("%d %d %d\n",i,j,dis);
			if(dis<=t){
				ans=max(ans,max(Abs(j-i+1),Abs(i-j+1)));
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
} 