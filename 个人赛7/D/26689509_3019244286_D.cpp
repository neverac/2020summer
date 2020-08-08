#include<cstdio>
using namespace std;
typedef long long ll;

ll conduct7(ll number, ll ans) {
	if (number == 1 || number == 0) return ans;
	if (number % 7 == 0) {
		ll temp = number / 7;
		if (temp & 1) ans += temp;
		ans = conduct7(temp, ans);
	}
	return ans;
}

ll conduct5(ll number, ll ans) {
	if (number == 1 || number == 0) return ans;
	if (number % 5 == 0) {
		ll temp = number / 5;
		if (temp & 1) ans += temp;
		ans = conduct5(temp, ans);
	}
	ans = conduct7(number, ans);
	return ans;
}

ll conduct3(ll number, ll ans) {
	if (number == 1 || number == 0) return ans;
	if (number % 3 == 0) {
		ll temp = number / 3;
		if (temp & 1) ans += temp;
		ans = conduct3(temp, ans);
	}
	ans = conduct5(number, ans);
	return ans;
}

ll conduct2(ll number, ll ans) {
	if (number == 1 || number == 0) return ans;
	if (number % 2 == 0) {
		ll temp = number / 2;
		if (temp & 1) ans += temp;
		ans = conduct2(temp, ans);
	}
	ans = conduct3(number, ans);
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll number;
		scanf("%lld", &number);
		ll ans = conduct2(number, 0);
		if (number & 1) ans += number;
		printf("%lld\n", ans);
	}
	return 0;
}