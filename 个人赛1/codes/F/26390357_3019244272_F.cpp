#include <bits/stdc++.h>
using namespace std;
int n, q;
long long num[100000 + 10];
int main(){
	cin >> n;
	long long ans = 0;
	while(n--){
		int x;
		cin >> x;
		num[x]++;
		ans += x;
	}
	cin >> q;
	while(q--){
		int b, c;
		cin >> b >> c;
		ans -= b * num[b];
		ans += c * num[b];
		num[c] += num[b];
		num[b] = 0;
		cout << ans << endl;
	}
	return 0;
}