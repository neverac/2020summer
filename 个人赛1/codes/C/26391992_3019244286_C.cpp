#include<cstdio>
#include<cstring>
using namespace std;

int code[100010];
int q[100010];
int tag[100010];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(tag, 0, sizeof(tag));
		memset(q, 0, sizeof(tag));
		memset(code, 0, sizeof(tag));
		bool can = 1;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", q + i);
		int presentmax = -1;
		for (int i = 0; i < n; i++) {
			if (q[i] > presentmax) {
				if (q[i] > n) {
					printf("-1");
					can = 0;
					break;
				}
				presentmax = q[i];
				code[i] = q[i];
				tag[q[i]] = 1;	
			}
			else {
				if (q[i] < i+1) {
					printf("-1");
					can = 0;
					break;
				}
			}
		}

		int index = 1;

		if (/*you*/can) {
			for (int i = 0; i < n; i++) {
				if (code[i] == 0) {
					for (index; tag[index]; ++index);
					code[i] = index;
					tag[index] = 1;
				}
			}
			for (int i = 0; i < n; i++) {
				if (i)printf(" ");
				printf("%d", code[i]);
			}
		}
		printf("\n");
	}
	return 0;
}