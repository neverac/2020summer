#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k,ans=0,ns;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &ns);
		ans += ns / k;
		if (ns % k) ans++;
	}
	ans -= (ans / 2);
	cout << ans;
	return 0;
}