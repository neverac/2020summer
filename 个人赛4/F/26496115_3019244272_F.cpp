#include <bits/stdc++.h>
using namespace std;
int main(){
	long long k, n, s, p;
	cin >> k >> n >> s >> p;
	long long a = (n + s - 1) / s;
	long long b = a * k;
	long long ans = (b  + p - 1) / p;
	cout << ans << endl;
	return 0;
}