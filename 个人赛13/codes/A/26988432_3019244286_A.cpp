#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n, m, x, y;
		scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
		ll ans = (n + (m - 1) * y) / x;
		if (ans > m)
			ans = m;
		printf("%lld\n", ans);
	}
	return 0;
}