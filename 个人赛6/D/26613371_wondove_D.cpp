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
int x[maxn],y[maxn],a[maxn];
int mp[110][110][11];
int s[110][110][11];
int_ main(){
	int n=read(),q=read(),c=read();
	for(int i=1;i<=n;++i){
		x[i]=read(),y[i]=read(),a[i]=read();
		mp[x[i]][y[i]][a[i]]++; 
	}
	for(int i=1;i<=100;++i){
		for(int j=1;j<=100;++j){
			for(int k=0;k<=c;++k){
				s[i][j][k]=(mp[i][j][k]+s[i][j-1][k]+s[i-1][j][k]-s[i-1][j-1][k]);
			}
		}
	}
	while(q--){
		int ans=0;
		int t=read(),x1=read(),y1=read(),x2=read(),y2=read();
		for(int i=0;i<=c;++i){
			int qwq=(t+i)%(c+1);
			ans+=qwq*(s[x2][y2][i]-s[x1-1][y2][i]-s[x2][y1-1][i]+s[x1-1][y1-1][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
} 