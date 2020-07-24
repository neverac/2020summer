#include <bits/stdc++.h>
using namespace std;

int num[100100], n;

int main() {
	char c;
	while (~(c = getchar())) {
		if (c >= '0' && c <= '9') num[++n] = c & 15;
	}
	int i;
	for (i = 1; i <= (n >> 1); ++i) swap(num[i], num[n - i + 1]);
	int int0[3] = { 2,3,4 };
	int ans[3] = { 1,1,1 };
	n = 2;
	while (n) {
		if (num[1] & 1) {
			for (int r = 0; r < 3; r++)  ans[r] = ans[r] * int0[r] % 5;
		}
		for (int r = 0; r < 3; r++) int0[r] = int0[r] * int0[r] % 5;
		for (int i = n; i; --i) {
			if (num[i] & 1) num[i - 1] += 10;
			num[i] >>= 1;
		}
		num[0] = 0;
		while (n && !num[n]) --n;
	} 
	printf("%d\n", (1+ ans[0] + ans[1] + ans[2]) % 5);
	return 0;
}
