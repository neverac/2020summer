#include<iostream>
#include<algorithm>
using namespace std;

bool visited[50][50];
struct house {
	int north, east, west, south;
}houses[50][50];

house patten[16]{
	{0,0,0,0},{0,0,1,0},{1,0,0,0},{1,0,1,0},{0,1,0,0},{0,1,1,0},{1,1,0,0},{1,1,1,0},{0,0,0,1}
	,{0,0,1,1},{1,0,0,1},{1,0,1,1},{0,1,0,1}, {0,1,1,1}, {1,1,0,1},{1,1,1,1}
};

int maxhouse = 0;
int housenumber = 0;

int dfs(int x, int y, int ans) {
	if (!visited[x][y]) {
		ans++;
		visited[x][y] = 1;
		if (!houses[x][y].east && !visited[x][y+1])//截断
			ans = dfs(x, y + 1, ans);
		if (!houses[x][y].west && !visited[x][y-1])
			ans = dfs(x, y-1, ans);
		if (!houses[x][y].north && !visited[x-1][y])
			ans = dfs(x-1, y, ans);
		if (!houses[x][y].south && !visited[x+1][y])
			ans = dfs(x+1, y, ans);
	}
	return ans;
}

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++) {
			int number;
			scanf("%d", &number);
			houses[i][j] = patten[number];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j])
				housenumber++;
			maxhouse = max(maxhouse, dfs(i, j, 0));
		}

	}
	printf("%d\n%d", housenumber, maxhouse);
	return 0;
}