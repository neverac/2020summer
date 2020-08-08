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

int_ main(){
	int T=read();
	while(T--){
		int n=read(),k=read();//3 7
		int qwq=ceil(1.0*k/(n-1));//3
	//	int qaq=qwq*n;//
		printf("%lld\n",k+qwq-1);
	}
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/