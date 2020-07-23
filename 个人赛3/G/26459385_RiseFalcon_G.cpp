#include <cstdio>
#include <cstring>
//#include <algorithm>
//using namespace std;
const int MAXN=1E5+10;
typedef long long LL;
const LL mod=998244353;
int len[MAXN],mp[18];
char w[MAXN][15];
LL input() {
	LL x;
	scanf("%lld",&x);
	return x;
}
LL merege(const char *a,int lena,const char*b,int lenb) {
	char fin[40]={0};
	int tail=0;
	if(lena>lenb) {
		for(int i=0;i<lena-lenb;++i) {
			fin[tail++]=a[i];
		}
		for(int i=lena-lenb;i<lena;++i) {
			fin[tail++]=a[i];
			fin[tail++]=b[i-(lena-lenb)];
		}	
	}else {
		for(int i=0;i<lenb-lena;++i) {
			fin[tail++]=b[i];
		}
		for(int i=lenb-lena;i<lenb;++i) {
			fin[tail++]=a[i-(lenb-lena)];
			fin[tail++]=b[i];
		}	
	}
	
	fin[tail]='\0';
	LL x=0;
	for(int i=0;i<tail;++i) {
		x=x*10+(fin[i]-'0');
		x%=mod;
	}
//	printf("f(%s,%s)->%s(%d)\n",a,b,fin,tail);
	return x;
}
int main() {
//	merege("1111",4,"2222",4);
//	merege("7777",4,"8888",3);-
//	merege("33",2,"44444",5);
//	merege("555",3,"6",1);
//	merege("111",3,"2222",4);
	int n=input();
	memset(mp,0,sizeof mp);
	for(int i=1;i<=n;++i) {
		scanf("%s",w[i]);
		len[i]=strlen(w[i]);
		mp[len[i]]++;
	}
	LL ans=0;
	const char zero[15]="00000000000";
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=10;++j) {
			LL dx=merege(w[i],len[i],zero,j)%mod;
			ans+=mp[j]*(dx)%mod;
			ans%=mod;
	//		printf("%lld %lld\n",mp[j],dx);
		}
		for(int j=1;j<=10;++j) {
			LL dx=merege(zero,j,w[i],len[i])%mod;
			ans+=mp[j]*(dx)%mod;
			ans%=mod;
	//		printf("%lld %lld\n",mp[j],dx);
		}
	}
	printf("%lld\n",ans);
	return 0;
} 