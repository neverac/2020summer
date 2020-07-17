
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <ctime>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define dow(i,j,k) for(int i = j; i >= k; i--)
#define ez(i,x) for(int i = h[x]; i; i = e[i].next)
#define fi first
#define se second
#define MS(x) memset(x, 0, sizeof(x))
using namespace std;
const int N = 1e5 + 100;

int n, m, h;

int l[105], s[105], a[105][105];
bool isl[105], iss[105];

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> h;
	rep(i,1,m) cin >> s[i];
	rep(i,1,n) cin >> l[i];
	int flag = 1;
	rep(i,1,n) rep(j,1,m) {
		int x;
		cin >> x;
		if (x == 1) {
			a[i][j] = min(s[j], l[i]);
			//if (a[i][j] == 0) flag = 0;
			if (a[i][j] == s[j]) iss[j] = 1;
			if (a[i][j] == l[i]) isl[i] = 1;
		}
	} 

	if(flag) {
		rep(i,1,n) {
			rep(j,1,m) cout << a[i][j] << " " ; cout << endl;
		}
	}
} 