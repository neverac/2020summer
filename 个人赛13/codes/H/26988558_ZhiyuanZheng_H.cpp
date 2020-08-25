#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const long long MOD=998244353;
int n,m;
long long a[510][510];
long long hang[510],lie[510],k;
int main(){
	IO;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>a[i][j];
			a[i][j]%=MOD;
		}
	}
	for (int i=1;i<=k;i++){
		char c;
		long long x,t;
		cin>>c>>x>>t;
		if (c=='r'){
			hang[x]=max(hang[x],t);
		}else{
			lie[x]=max(lie[x],t);
		}
	}
	long long ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			ans=(ans+(max(hang[i],lie[j])%MOD*a[i][j])%MOD)%MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}

