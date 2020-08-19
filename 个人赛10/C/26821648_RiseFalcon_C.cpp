#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2E5+10;
const int MD=26;
int tong [MAXN][MD];
string s;
int counts(int l,int r) {
	int cnt=0;
	for(int k=0;k<MD;++k) {
		cnt+=(tong[r][k]-tong[l-1][k]>0);
	}return cnt;
}
int main() {
	cin>>s;
	int n=s.length();s=" "+s;
	for(int i=1;i<=n;++i) {
		memcpy(tong[i],tong[i-1],sizeof(int)*MD);
		tong[i][s[i]-'a']++;
	}
	int m;cin>>m;
	for(int i=1;i<=m;++i) {
		int l,r;cin>>l>>r;
		if(l==r)cout<<"Yes"<<endl;
		else if(s[l]!=s[r])cout<<"Yes"<<endl;
		else if(counts(l,r)>=3)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}