#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef int int_;

#define int long long
#define maxn 2000010
const int Mod=998244353;
const int inf=1e9+7;
const int p=998244353;
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
int qwq[maxn];
char str[maxn];
int_ main(){
	int k=read();
	scanf("%s",str+1);
	int n=strlen(str+1);
	int ans=0;
	for(int i=1;i<=26;++i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			if(str[j]-'a'==i-1) qwq[++cnt]=j;
			if(cnt==0) continue;
			if(cnt<=k) ans+=qwq[cnt];
			else ans+=qwq[cnt]-qwq[cnt-k];
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
/*
1
1 4
*/