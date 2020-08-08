#include<cstdio>
#include<algorithm>
using namespace std;

int tastness[100005];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) 
			scanf("%d", tastness + i);
		long long sum = tastness[0], l = 0, r =0, nowl = 0, total = tastness[0], maxsum = tastness[0];
		for (int i = 1; i < n; ++i) {
			total += tastness[i];
			if (sum > 0) {
				sum += tastness[i];
			}
			else {
				sum = tastness[i];
				nowl = i;
			}
			if (sum > maxsum && (nowl!=0||i!=n-1)) {
				maxsum = sum;
				l = nowl;
				r = i;
			}
		}

		long long temp = total;
		for (int i = 0; i < n - 1; ++i) {
			temp -= tastness[i];
			maxsum = max(maxsum, temp);
		}
		temp = total;
		for (int i = n - 1; i > 0; --i) {
			temp -= tastness[i];
			maxsum = max(maxsum, temp);
		}

		if (maxsum < total) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}