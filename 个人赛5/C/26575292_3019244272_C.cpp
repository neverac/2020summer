#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[500], w[500];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> w[i];
	f[0] = 100;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			ll t = f[j - 1] / w[j];
			t = min(100000LL, t);
			f[i] = max(f[i], f[j - 1] + (w[i] - w[j]) * t);
		}
	}
	cout << f[n] << endl;
	return 0;
}