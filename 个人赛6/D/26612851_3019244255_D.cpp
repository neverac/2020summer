#include <iostream>
using namespace std;

int dp[15][110][110];
int kk[15][110][110];

int main()
{
	int n, q, c, x, y, s;
	cin >> n >> q >> c;
	for(int i = 0; i < n; i ++)
	{
		cin >> x >> y >> s;
		for(int j = 0; j <= c; j ++)
		kk[j][x][y] += (s + j) % (c + 1);
	}
	for(int i = 0; i <= c; i ++)
	{
		for(int j = 0; j <= 100; j ++)
		{
			for(int k = 0; k <= 100; k ++)
			dp[i][j][k] = kk[i][j][k] + dp[i][j - 1][k] + dp[i][j][k - 1] - dp[i][j - 1][k - 1];	
		}
	}
	while(q --)
	{
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		t %= c + 1;
		int sum = dp[t][x2][y2] - dp[t][x1 - 1][y2] - dp[t][x2][y1 - 1] + dp[t][x1 - 1][y1 - 1];
		cout << sum << endl;
	}
	return 0;
}