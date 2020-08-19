#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin >> n;
	vector<int>a(n*2);
	for (int i = 0; i < n * 2; i++) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
    long long ans = 1ll * abs(a[n-1] - a[0]) * abs(a[n*2-1] - a[n]);
	for (int i = n; i < n * 2 - 1; i++) {
        ans = min(ans, 1ll * (a[i] - a[i-n+1]) * (a[2*n-1] - a[0]));
    }
    cout << ans << endl;
}