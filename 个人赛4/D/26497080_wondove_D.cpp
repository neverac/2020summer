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
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int ans[]={4,0,0,0};
char str[10000010];
int_ main(){
	int T=read();
	for(int tt=1;tt<=T;++tt){
		int n=read(),a=read(),b=read();
		int d=gcd(a,b);
		int qwq=n/d;
		printf("Case #%d: ",tt);
		puts((qwq&1)==0?"Iaka":"Yuwgna");
	}
    return 0;
}
