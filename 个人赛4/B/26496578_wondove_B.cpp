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
int ans[]={4,0,0,0};
char str[10000010];
int_ main(){
	scanf("%s",str+1);
	int len=strlen(str+1);
	int x=str[len-1]-'0';
	int y=str[len]-'0';
	int qwq=x*10+y;
	qwq%=4;
	printf("%lld",ans[qwq]);
    return 0;
}
