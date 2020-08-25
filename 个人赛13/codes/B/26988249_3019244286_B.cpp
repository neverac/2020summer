#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	double ans = 1e+9;
	for (int i = 0; i < n; ++i) {
		double x, y, z;
		scanf("%lf%lf%lf", &x, &y, &z);
		ans = min(ans, sqrt(x * x + y * y + z * z));
	}
	printf("%.3lf\n", ans);
	return 0;
}