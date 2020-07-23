#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
long long h[maxn][2];
long long f[maxn][2][2];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i][0];
	}
	for(int i = 1; i <= n; i++){
		cin >> h[i][1];
	}
	f[1][0][0]= 0;
	f[1][1][0] = h[1][0];
	f[1][0][1] = h[1][1];
	for(int i = 2; i <= n; i++){
		f[i][0][0] = max(max(f[i - 1][1][0], f[i - 1][0][1]), f[i - 1][0][0]);
		f[i][1][0] = h[i][0] + max(f[i - 1][0][0], f[i - 1][0][1]);
		f[i][0][1] = h[i][1] + max(f[i - 1][0][0], f[i - 1][1][0]);
	}
	cout << max(f[n][0][0], max(f[n][1][0], f[n][0][1])) << endl;
	return 0;
}