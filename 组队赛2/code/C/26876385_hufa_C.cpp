#include<cstdio>
using namespace std;

int number[55];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", number + i);
	}

	bool tag = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (i != j && j != k && i != k) {
					if ((number[i] - number[j]) % number[k]) {
						printf("no\n");
						tag = 0;
						break;
					}
				}
				if (!tag) break;
			}
			if (!tag) break;
		}
		if (!tag) break;
	}

	if (tag) {
		printf("yes\n");
	}
	return 0;
}