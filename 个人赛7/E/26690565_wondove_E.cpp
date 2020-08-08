#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
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
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
int a[100010];
int_ main(){
	int n=read(),m=read();
	for(int i=1;i<=m;++i){
		a[i]=read();
	}int bns=0;
	for(int i=1;i<=(1<<m)-1;++i){
		int qwq=0;
		int x=i;
		int ans=1,QAQ=0;
		while(x){
			++qwq;
			if(x&1){
				ans=lcm(ans,a[qwq]);
				++QAQ;
			}
			x>>=1;
		}
		if(QAQ&1) bns+=n/ans;
		else bns-=n/ans;
	}
	printf("%lld\n",bns);
	return 0;
} 
/*
1
1 4
*/