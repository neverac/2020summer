
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

int n, m;
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	vector<int>a(n+1), b(m + 1);
	int mx = 0;
	long long sum = 0;
	rep(i,1,n) {
		cin >> a[i], mx = max(a[i], mx);
		sum += m * 1ll * a[i];
	}
	sort(a.begin(),a.end());
	int flag = 1;
	rep(i,1,m) {
		cin >> b[i];
		if (b[i] < mx) {
			cout << "-1" << endl;
			return 0;
		}
		if (b[i] == mx) flag = 0;
		sum += b[i] - mx;
	}
	if (flag) {
		if (n == 1) {
			cout << "-1\n";
			return 0;
		}
		sum += a[n] - a[n-1];
	}

	cout << sum <<endl;
}