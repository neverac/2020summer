#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n, k;
	cin >> n >> k;
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		long long x;
		cin >> x;
		ans += (x + k - 1) / k;
	}
	ans = (ans + 1) / 2;
	cout << ans << endl;
	return 0;
}