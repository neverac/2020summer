#include<bits/stdc++.h>
using namespace std;
int main() {
	long long int a, b,c,ans=0;
	cin >> a >> b;
	while (1){
		if (a < b) swap(a, b);
		c = a / b;
		ans += c;
		a -= c * b;
		if (!a) break;
	}
	cout << ans;
	return 0;
}