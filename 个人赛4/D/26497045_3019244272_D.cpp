#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	int cnt = 0;
	while(t--){
		int n, a, b, g;
		cin >> n >> a >> b;
		g = __gcd(a, b);
		if(n / g & 1) cout << "Case #" << ++cnt << ": Yuwgna" << endl;
		else cout << "Case #" << ++cnt << ": Iaka" << endl;
	}
	return 0;
}