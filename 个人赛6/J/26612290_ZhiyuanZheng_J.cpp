#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100010];
int main(){
	cin>>n>>k;
	long long ans=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=ceil(1.0*a[i]/k);
	}
	int tt=0;
	for (int i=1;i<=n;i++){
		if (a[i]%2==1) tt++;
		ans+=a[i]/2;
	}
	ans+=ceil(1.0*tt/2);
	cout<<ans<<endl;
	return 0;
}

