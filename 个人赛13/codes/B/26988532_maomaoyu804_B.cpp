#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
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
struct Edge{
	int u,v,w,next;
}E[maxn<<1];
int ecnt=0,head[maxn];
void addedge(int u,int v){
	E[++ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}
void Addedge(int u,int v){
	addedge(u,v);
	addedge(v,u);
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
int_ main(){
	int n=read();
	int ans=1e9;
	for(int i=1;i<=n;++i){
		int x=read(),y=read(),z=read();
		ans=min(ans,x*x+y*y+z*z);
	}
	double bns=sqrt(1.0*ans);
	printf("%.3lf",bns);
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/