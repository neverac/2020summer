#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int player[2][100010];
long long int maxv[2][100010];


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &player[0][i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &player[1][i]);

	maxv[0][n] = 0;
	maxv[1][n] = 0;
	maxv[0][n - 1] = player[0][n - 1];
	maxv[1][n - 1] = player[1][n - 1];

	for (int i = n - 2; i >= 0; --i) {
		maxv[0][i] = max(maxv[1][i + 1] + player[0][i], maxv[1][i + 2] + player[0][i]);
		maxv[1][i] = max(maxv[0][i + 1] + player[1][i], maxv[0][i + 2] + player[1][i]);
	}
	long long int ans = 0;
	ans = max(ans, maxv[0][0]);
	ans = max(ans, maxv[0][1]);
	ans = max(ans, maxv[1][0]);
	ans = max(ans, maxv[1][1]);
	printf("%lld\n", ans);
	return 0;
}