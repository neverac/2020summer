#include<cstdio>
#include<algorithm>
using namespace std;

long long number[200005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; ++i)
		scanf("%lld", number + i);
	sort(number, number + 2 * n);
	long long tmp = number[2 * n - 1] - number[n];
	long long area = tmp*(number[n-1] - number[0]);
	tmp = number[2 * n - 1] - number[0];
	for (int i = 1; i < n; i++)
		area = min(area, tmp * (number[n+i-1]-number[i]));
	printf("%lld\n", area);
	return 0;
}