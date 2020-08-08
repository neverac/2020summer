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
int a[maxn],b[maxn];
int_ main(){
	int n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i) b[i]=read();
	int max1=0,max2=0,mm,mn;
	for(int i=1;i<=n;++i){
		if(a[i]>max1) max1=a[i],mm=i;
		if(b[i]>max2) max2=b[i],mn=i;
	}
	if(max1>max2){
		for(int i=1;i<=n;++i){
			if(a[i]>max2){
				printf("%d\n",n-i+1);
				break;
			}
		}
	}
	else{
		for(int i=1;i<=n;++i){
			if(b[i]>max1){
				printf("%d\n",n-i+1);
				break;
			}
		}
	}
	return 0;
} 
/*
1
1 4
*/