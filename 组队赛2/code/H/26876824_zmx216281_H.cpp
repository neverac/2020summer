#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		long long n; 
		scanf("%lld",&n);
		long long ans=(n*(n+1)^(n+1));
		cout << ans << endl;
	}
}