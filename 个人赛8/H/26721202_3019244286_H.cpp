#include<cstdio>
#include<algorithm>
using namespace std;

int number[200005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", number + i);
	}
	int ans = 1;
	int temp1 = 1, temp2 = 1;
	int tag = 1;
	for (int i = 1; i < n; ++i) {
		if (number[i] > number[i - 1]) {
			temp1++;
			temp2++;
		}
		else {
			if (i < n - 1) {
				if (tag) {
					if (i == 1 || number[i] > number[i - 2]) {
						tag = 0;
					}
					else if (number[i+1] > number[i - 1]) {
						tag = 0;
					}
					else {
						temp2 = 1;
					}
				}
				else{
					ans = max(ans, temp2);
					temp2 = temp1;
					tag = 1;

					if (i == 1 || number[i] > number[i - 2]) {
						tag = 0;
					}
					else if (number[i + 1] > number[i - 1]) {
						tag = 0;
					}
					else {
						temp2 = 1;
					}
					
				}
			}
			ans = max(ans, temp1);
			temp1 = 1;
		}
	}
	ans = max(ans, temp1);
	ans = max(ans, temp2);
	printf("%d", ans);
	return 0;
}
//10 100 101 4 102 103 5 105 106 107 108