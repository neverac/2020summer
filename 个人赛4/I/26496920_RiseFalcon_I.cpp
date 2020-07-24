#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
const LL mod=998244353;
const LL dx=10007;
LL px[MAXN];
LL pa[MAXN];int lena;
LL pb[MAXN];int lenb;
string w[MAXN],a; 
bool judge(int la,int ra,int lb,int rb) {
	LL ha=(pa[ra]+mod-pa[la-1]*px[ra-la+1]%mod)%mod;
	LL hb=(pb[rb]+mod-pb[lb-1]*px[rb-lb+1]%mod)%mod;
//	printf("(%d,%d):%lld (%d,%d):%lld\n",la,ra,ha,lb,rb,hb);
	return ha==hb;
}
int merege(const string&b) {
	
	lenb=b.length();
	pb[0]=0;
	for(int i=1;i<=lenb;++i) {
		pb[i]=(pb[i-1]*dx%mod+(b[i-1]))%mod;
	}
	int lenc=min(lena,lenb),ans=0;
	for(int i=1;i<=lenc;++i) {
		if(judge(lena-i+1,lena,1,i)) {
			ans=i;
		}
	}
	a+=b.substr(ans,lenb);
	for(int i=0;i<lenb-ans;++i) {
		pa[i+lena+1]=(pa[lena+i]*dx%mod+b[i+ans])%mod;
//		printf("(%d,%d)\n",i+lena+1,i+ans);
	}
	lena+=lenb-ans;
	/*
	for(int i=0;i<=lena;++i) {
		printf("%lld ",pa[i]);
	}printf("\n");
	*/
	return ans;
}
int main() {
	px[0]=1;
	for(int i=1;i<=1E6+2;++i) {
		px[i]=px[i-1]*dx%mod;
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;++i) {
		cin>>w[i];
	}
	a=w[1];
	lena=a.length();
	for(int i=1;i<=lena;++i) {
		pa[i]=(pa[i-1]*dx%mod+a[i-1])%mod; 
	}
	for(int i=2;i<=n;++i) {
		merege(w[i]);
	}
	cout<<a<<endl;
	return 0;
} 