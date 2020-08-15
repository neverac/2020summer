#include<cstdio>
#include<algorithm>
using namespace std;

int step[500005];

int main() {
	int r, s, p, a, b;
	scanf("%d%d%d", &r, &s, &p);
	for (int i = 0; i < p; ++i) {
		scanf("%d%d", &a, &b);
		if (b > s) b = 2 * s - b + 1;
		step[i] = r - a + 1 + s - b + 1;
	}
	sort(step, step + p);
	for (int i = 1; i < p; ++i) 
		step[i] = max(step[i], step[i - 1] + 1);
	printf("%d\n", step[p - 1]);
	return 0;
}