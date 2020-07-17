#include <bits/stdc++.h>
using namespace std;
int n, m, h;
int a[150], b[150], c[150][150];
int main(){
	cin >> n >> m >> h;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> c[i][j];
			c[i][j] *= min(a[j], b[i]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}