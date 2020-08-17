#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int check[16][505];
int checked[505];

int step = 100000;
void DFS(int m,int n,int now,int st) {
	st++;
	int tag = 1;
	int temp[505];
	for (int i = 0; i < n; ++i) {
		temp[i] = checked[i];
	}
	for (int i = 0; i < n; ++i) {
		checked[i] = checked[i] || check[now][i];
		if (!checked[i]) tag = 0;
	}
	if (tag) {
		step = min(step, st);

	}
	else {
		for (int i = now + 1; i < m; ++i) {
			DFS(m,n, i, st);
		}
	}
	for (int i = 0; i < n; ++i) {
		checked[i] = temp[i];
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(checked, 0, sizeof(checked));
		step = 100000;
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i) {
			getchar();
			for (int j = 0; j < n; ++j) {
				char c;
				scanf("%c", &c);
				check[i][j] = c - '0';
			}
		}

		for (int i = 0; i < m; ++i) {
			DFS(m,n,i,0);
		}
		if (step == 100000) step = -1;
		printf("%d\n", step);
	}
	return 0;
}