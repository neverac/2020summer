#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std; 
typedef long long LL;
const int MAXN=1E5+10;
int q[MAXN],tong[MAXN],a[MAXN];
long long sumans;
string name(LL N) {
	N-=1;
	LL pw=26,i=1;
	while(N>=pw) {
		N-=pw;
		pw*=26;
		++i;
	}
//	printf("%lld %lld %lld\n",N,pw,i);
	string names="";
	while(N>0) {
		LL r=N%26;
		names=char(r+'a')+names;
		N/=26;
	}
	int x=names.length();
	if(x!=i) {
		names=string(i-x,'a')+names;
	}
	return names;
}
int main() {
	LL N;
	scanf("%lld",&N);
	printf("%s",name(N).c_str());
	return 0;
} 