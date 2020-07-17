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
int A[110][110];
int B[110][110];
int a[maxn],b[maxn];
int_ main(){
	int n=read(),m=read(),h=read();
	for(int i=1;i<=m;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i) b[i]=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&A[i][j]);
			if(A[i][j]){
				B[i][j]=min(b[i],a[j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",B[i][j]);
		}
		puts("");
	}
} 