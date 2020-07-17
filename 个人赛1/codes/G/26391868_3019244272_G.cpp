#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, m;
int b[maxn], g[maxn];
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= m; i++) cin >> g[i];
	sort(b + 1, b + n + 1);
	sort(g + 1, g + m + 1);
	if(b[n] > g[1]){
		cout << -1 << endl;
		return 0;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++) ans += b[i];
	ans *= m;
	bool flag = false;
	for(int i = 1; i <= m; i++){
		ans += g[i] - b[n];
		if(g[i] == b[n]) flag = true;
	}
	if(!flag) ans += b[n] - b[n - 1];
	cout << ans << endl;
	return 0;
}

/*

0 0
1 1

*/