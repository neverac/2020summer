#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long a[maxn*2];
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=2*n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+2*n);
	long long ans=(a[n]-a[1])*(a[2*n]-a[n+1]);
	for (int i=1;i<=n;i++){
		ans=min(ans,(a[2*n]-a[1])*(a[i+n-1]-a[i]));
	}
	cout<<ans<<endl;
	return 0;
} 