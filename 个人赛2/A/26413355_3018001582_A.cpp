#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int c[60][60];
bool g[60][60] = { 0 };

struct point
{
	int x, y;
};
queue<point> points;
point p, new_p;
int x, y;
int BFS(int i, int j) {
		int sum = 1;
		g[i][j] = 1;
		p.x = i; p.y = j;
		points.push(p);
		while (points.size()) {
			p = points.front();
			points.pop();
			i = p.x;j=p.y;
			for (int k = 1; k <= 8; k *= 2) {
				if (k == 2) {
					if ((!g[i - 1][j]) && (!(c[i][j] & 2))) {
						new_p.x = i - 1; new_p.y = j;
						g[i - 1][j] = 1;
						sum += 1; points.push(new_p);
					}
				}
				else if (k == 1) {
					if ((!g[i][j-1]) && (!(c[i][j] & 1))) {
						new_p.x = i; new_p.y = j-1;
						g[i][j-1] = 1;
						sum += 1; points.push(new_p);
					}
				}
				else if (k == 8) {
					if ((!g[i + 1][j]) && (!(c[i][j] & 8))) {
						new_p.x = i + 1; new_p.y = j;
						g[i + 1][j] = 1;
						sum += 1; points.push(new_p);
					}
				}
				else if (k == 4) {
					if ((!g[i][j + 1]) && (!(c[i][j] & 4))) {
						new_p.x = i; new_p.y = j+1;
						g[i][j+1] = 1;
						sum += 1; points.push(new_p);
					}
				}
			}
		}
		return sum;
}
int main() {
	int sum,maxr=0,sumr=0;
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf("%d", &c[i][j]);
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (!g[i][j]) {
				sumr++;
				sum = BFS(i, j);
				maxr = max(maxr, sum);
			}
		}
	}
	cout << sumr<<'\n'<<maxr;
	return 0;
}
