#include<cstdio>
using namespace std;
int a[102],b[102];
int main() {
	int n,i,j;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (j = 1; j <= n; ++j)
		scanf("%d", b+j);
	i--, j--;
	while (i && j) {
		while (j && a[n - i + 1] > b[n - j + 1])
			j--;
		while (i &&  b[n - j + 1] > a[n - i + 1])
			i--;
	}
	printf("%d\n", i + j);
	return 0;
}