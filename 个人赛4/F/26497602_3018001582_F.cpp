#include<bits/stdc++.h>
using namespace std;
int main() {
	double n, p, s, k;
	cin >> n >> p >> s >> k;
	int ans = ceil((n * (ceil(p / s))) / k);
	cout << ans;
	return 0;
}