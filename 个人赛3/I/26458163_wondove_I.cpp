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

char str[maxn];
int_ main(){
	int n=read();
	int qwq=0;
	scanf("%s",str+1);
	for(int i=1;i<=n;++i){
		if(str[i]=='+') ++qwq;
		else --qwq,qwq=max(0ll,qwq);
	}
	printf("%lld\n",qwq);
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/