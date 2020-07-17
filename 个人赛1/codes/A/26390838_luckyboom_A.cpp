#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=1;i<=k;i++)ans+=a[i];
	cout<<ans<<endl;
return 0;
}