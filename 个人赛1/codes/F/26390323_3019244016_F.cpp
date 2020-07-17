
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


int main() {
    int n;
	ios::sync_with_stdio(0);
	cin >> n;
	map<int,int> m;
	long long sum = 0;
	rep(i,1,n) {
		int x;
		cin >> x;
		m[x]++;
		sum += x;
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		sum = sum - 1ll * m[x] * x + m[x] * 1ll * y;
		m[y] += m[x];
		m[x] = 0;
		cout << sum << "\n";
	}
}