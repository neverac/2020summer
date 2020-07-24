#include<cstdio>
using namespace std;

int main() {
	int k, n, s, p;
	scanf("%d%d%d%d", &k, &n, &s, &p);
	printf("%d\n", ((n + s - 1) / s * k + p - 1) / p);
	return 0;
}