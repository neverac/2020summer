#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, mx = 100000;
int a[maxn];
long long c[maxn];
void update(int p){
	for(; p <= mx; p += p & -p) c[p]++;
}
long long query(int p){
	long long s = 0;
	for(; p; p -= p & -p) s += c[p];
	return s;
}
long long f[maxn], g[maxn];
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		f[i] = query(mx) - query(a[i]);
		update(a[i]);
	}
	memset(c, 0, sizeof c);
	for(int i = n; i; i--){
		g[i] = query(mx) - query(a[i]);
		update(a[i]);
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		ans += min(f[i], g[i]);
	}
	cout << ans << endl;
	return 0;
}