#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m;
ll a[11];
ll ans;
void work(int w, int tot, ll s){
	if(s > n) return;
	if(w == m + 1){
		if(tot){
			if(tot & 1) ans += n / s;
			else ans -= n / s;
		}
		return;
	}
	work(w + 1, tot + 1, s * a[w] / __gcd(s, a[w]));
	work(w + 1, tot, s);
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	work(1, 0, 1);
	cout << ans << endl;
	return 0;
}