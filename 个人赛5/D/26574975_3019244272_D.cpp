#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll T;
	cin >> T;
	while(T--){
		ll n, k;
		cin >> n >> k;
		ll l = 1, r = 1LL << 60, mid, tmp, ans;
		while(l <= r){
			mid = l + r >> 1;
			tmp = mid - mid / n;
			if(tmp >= k){
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}