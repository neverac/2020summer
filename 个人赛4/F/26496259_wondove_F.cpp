#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 1000010

typedef int int_;
#define int long long
const int inf=(1ll<<61)-1;
inline int read(){
    int ret=0,ff=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') ff=-ff;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        ret=ret*10ll+ch-'0';
        ch=getchar();
    }
    return ret*ff;
}

int_ main(){
	int n=read(),k=read(),m=read(),s=read();
	int qwq=0.9999+1.0*k/m;
	int qaq=qwq*n;
	int ans=0.9999+1.0*qaq/s;
	printf("%lld\n",ans);
    return 0;
}
