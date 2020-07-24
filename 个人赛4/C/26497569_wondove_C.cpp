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
int a[1000010];
int_ main(){
	int T=read();
	while(T--){
		bool flg=0;
		int n=read(),x=read();
		scanf("%s",str+1);
		for(int i=1;i<=n;++i){
			a[i]=a[i-1]+(str[i]=='0'?1:-1);
			if(a[i]==x){
				flg=1;
			}
		}
		if(a[n]==0){
			if(flg==1) puts("-1");
			else puts("0");
			continue;
		}
		int qwq=0;
		for(int i=1;i<=n;++i){
			if((x-a[i])%a[n]==0&&(x-a[i])*a[n]>=0){
				++qwq;
			}
		}
		if(x==0) ++qwq;
		printf("%lld\n",qwq);
	}
    return 0;
}
