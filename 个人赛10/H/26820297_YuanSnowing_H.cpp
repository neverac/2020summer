#include<bits/stdc++.h>
using namespace std;
int n,a[500],sum,ans;
int main(){
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> a[i];
		sum += a[i];
	}

	ans = 360;
	for(int i=0;i<n;++i){
		for(int j=i; j<n; ++j){
			int tmp=0;
			for(int k=i;k<=j;++k) tmp += a[k];
			ans = min(ans,abs(sum-tmp-tmp));
		}
	}
	cout << ans << endl;
	return 0;
}
