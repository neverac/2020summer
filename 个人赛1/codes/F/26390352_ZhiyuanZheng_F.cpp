#include <bits/stdc++.h>
using namespace std;
int n,q;
int a[200010];
int main(){
	cin>>n;
	long long sum=0;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]++;
		sum+=x;
	}
	cin>>q;
	while (q--){
		int x,y;
		cin>>x>>y;
		sum-=1ll*x*a[x];
		sum+=1ll*a[x]*y;
		a[y]+=a[x];
		a[x]=0;
		cout<<sum<<endl;
	}
	return 0;
}

