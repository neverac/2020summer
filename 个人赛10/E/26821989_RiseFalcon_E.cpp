#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2E5+10;
const int MD=26;
LL f[MAXN],a[MAXN];
int doing() {
	LL n,p,k;
	cin>>n>>p>>k;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
	}sort(a+1,a+n+1); 
	f[0]=0;
	for(int i=1;i<=n;++i) {
		f[i]=f[i-1]+a[i];
		if(i>=k)f[i]=min(f[i-k]+a[i],f[i]);
	}
	for(int i=n;i>=0;--i) {
		if(f[i]<=p) {
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false); 
	int T;cin>>T;
	while(T-->0)doing();
	return 0;
}