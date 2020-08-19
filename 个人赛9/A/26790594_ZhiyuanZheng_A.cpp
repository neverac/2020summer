#include<bits/stdc++.h>
using namespace std;
vector <long long> a;
int n;
long long ans;
int main(){
	cin>>n;
	for (int i=0;i<2*n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	
	ans=(a[n-1]-a[0])*(a[2*n-1]-a[n]);
	for (int i=0;i<n;i++)
		ans=min(ans,(a[i+n-1]-a[i])*(a[2*n-1]-a[0]));
	cout<<ans<<endl;
	return 0;
} 