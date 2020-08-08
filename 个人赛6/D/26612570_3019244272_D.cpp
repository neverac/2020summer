#include<bits/stdc++.h>
const int maxn = 100 + 10;
long long num[maxn][maxn][11];
using namespace std;
int main(){
	int n, q, c;
	cin >> n >> q >> c;
	for(int i = 1; i <= n; i++){
		int x, y, s;
		cin >> x >> y >> s;
		num[x][y][s]++;
	}
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100; j++){
			for(int s = 0; s <= c; s++){
				num[i][j][s] += num[i - 1][j][s] + num[i][j - 1][s] - num[i - 1][j - 1][s];
			}
		}
	}
	while(q--){
		int t, xa, ya, xb, yb;
		cin >> t >> xa >> ya >> xb >> yb;
		long long ans = 0;
		t %= c + 1;
		for(int s = 0; s <= c; s++){
			long long tmp;
			tmp = num[xb][yb][s] + num[xa - 1][ya - 1][s] - num[xa - 1][yb][s] - num[xb][ya - 1][s];
			ans += (s + t) % (c + 1) * tmp;
		}
		cout << ans << endl;
	}
	return 0;
}