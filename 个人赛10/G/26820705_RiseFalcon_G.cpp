#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
LL a[MAXN],f[MAXN];
vector<LL>g[MAXN];
bool cmp (const vector<LL>&a,const vector<LL>&b) {
	int lena=a.size();
	int lenb=b.size();
	int len=min(lena,lenb);
	for(int i=0;i<len;++i) {
		if(a[i]<b[i])return true;
		if(a[i]>b[i])return false;
	}return lena<lenb;
}
void update(int x,int k) {
	auto h=g[k-1];
	h.push_back(x);
	if(f[k]<f[k-1]+x) {
		f[k]=f[k-1]+x;
		g[k]=h;
	}else if(f[k]==f[k-1]+x&&cmp(h,g[k])) {
		g[k]=h;
	}
	
}
int main() {
	int n;cin>>n;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
	}
	for(int i=1;i<=n;++i) {
		for(int k=n;k>=1;--k) {
			if(f[k-1]==0)continue;
			update(a[i],k);
		}
		update(a[i],1);
	}
	int m;cin>>m;
	for(int i=1;i<=m;++i) {
		int k;int pos;
		cin>>k>>pos;
		printf("%d\n",g[k][pos-1]);
	}
	return 0;
}




















