#include <iostream>
using namespace std;
typedef long long ll;
ll p[] = {0, 3, 5, 7};
ll ksm(ll a, ll b){
	ll s = 1;
	while(b){
		if(b & 1) s *= a;
		a *= a;
		b >>= 1;
	}
	return s;
}
int main(){
	ll T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		ll ans = 1;
		for(int i = 1; i <= 3; i++){
			if(n % p[i] == 0){
				int cnt = 0;
				while(n % p[i] == 0){
					cnt++;
					n /= p[i];
				}
				ans *= (ksm(p[i], cnt + 1) - 1) / (p[i] - 1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}