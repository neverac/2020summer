#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int p[maxn];
int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	sort(p + 1, p + n + 1);
	int ans = 0;
	for(int i = 1; i <= k; i++) ans += p[i];
	cout << ans << endl;
	return 0;
}