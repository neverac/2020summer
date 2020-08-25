	#include<cstdio>
	#include<algorithm>
	using namespace std;
	typedef long long ll;
	const int mod = 998244353;
	ll caofarm[500][500];
	ll opr[500], opc[500];
	int main() {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		ll aij;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%lld", &aij);
				caofarm[i][j] = aij % mod;
			}
		}

		char op;
		ll l, t;
		for (int i = 0; i < k; ++i) {
			getchar();
			scanf("%c%lld%lld", &op, &l, &t);
			l--;
			if (op == 'r') opr[l] = t;
			else opc[l] = t;
		}
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ans += caofarm[i][j] * (max(opr[i], opc[j]) % mod);
				ans %= mod;
			}
		}
		printf("%lld\n", ans);
		return 0;
	}