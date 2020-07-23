#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
const int maxn =1e5+10;
long long a[maxn];
vector <long long> v[20];
int n;
void does(long long x){
	long long cnt=0,tmp=x;
	while (tmp){
		cnt++;
		tmp/=10;
	}
	v[cnt].push_back(x);
}
long long getsum(long long t,long long ten,int p,bool w){
	int l=0;
	long long sum=0;
	while (t){
		long long x=t%10;
		sum=(sum+x*ten%MOD)%MOD;
		t/=10;
		l++; 
		if (w==1)
			if (l<p) ten*=100;else ten*=10;
		else 
			if (l<=p) ten*=100;else ten*=10;
		ten%=MOD; 	
	}
	return sum;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		does(a[i]);
	}
	long long ans=0;
	for (int i=1;i<=10;i++){
		for (int j=1;j<=10;j++){
			for (int k=0;k<v[i].size();k++){
				long long sum=getsum(v[i][k],10,j,1);
//				cout<<i<<" "<<j<<" "<<v[i][k]<<endl;
//				cout<<sum<<" ";
				ans=(ans+1ll*v[j].size()*sum%MOD)%MOD;
				sum=getsum(v[i][k],1,j,0);
//				cout<<sum<<endl;
				ans=(ans+1ll*v[j].size()*sum%MOD)%MOD;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

