#include<cstdio>
using namespace std;
typedef long long ll;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n, k;
		scanf("%lld%lld", &n, &k);
		ll ans;
		if (k % (n - 1) == 0)
			ans = k / (n - 1) * n - 1;
		else {
			ans = k / (n - 1) * n;
			ans +=k % (n-1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}