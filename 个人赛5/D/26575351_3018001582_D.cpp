#include<bits/stdc++.h>
using namespace std;
int main() {
	int sum;
	cin >> sum;
	for (int i = 0; i < sum; i++) {
		long long int n, k,ans;
		scanf("%lld %lld", &n, &k);
		if (!(k % (n - 1))) {
			ans = n * (k / (n - 1)) - 1;
		}
		else {
			ans = (k / (n - 1)) * n + k % (n - 1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}