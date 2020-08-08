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
int a[maxn];
int_ main(){
	int n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int ans=100;
	int qwq=0;
	int qaq=100;
	for(int i=1;i<=n;++i){
		if(qaq>=a[i]){
			qwq=min(qwq,100000ll);
			qwq=ans/a[i];
			qaq=a[i];
		}
		else{
			qwq=min(qwq,100000ll);
			ans+=(a[i]-qaq)*qwq;
			qaq=a[i];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/