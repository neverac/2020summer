#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
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
int a[maxn];
int b[maxn],dp[maxn][4];
char str[maxn];
int_ main(){
	int qwq=0,qaq=0;
	int n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]==1) ++qwq;
		else ++qaq;
	}
	if(qwq&&qaq){
		printf("2 1");
		for(int i=1;i<qaq;++i) printf(" 2");
		for(int i=1;i<qwq;++i) printf(" 1");
	}
	else{
		for(int i=1;i<=qaq;++i) printf("2 ");
		for(int i=1;i<=qwq;++i) printf("1 ");
	}
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/