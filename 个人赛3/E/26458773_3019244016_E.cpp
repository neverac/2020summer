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
#include <list>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define dow(i,j,k) for(int i = j; i >= k; i--)
#define ez(i,x) for(int i = h[x]; i; i = e[i].next)
#define fi first
#define se second
#define MS(x) memset(x, 0, sizeof(x))
#pragma GCC optimize(3)
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pi;


int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int>a(n), b(n);
	rep(i,0,n-1) {
		cin >> a[i];
	}
	rep(i,0,n-1) {
		cin >> b[i];
	}
	long long f = 0, g = 0;
	rep(i,0,n-1) {
		long long tmpf = f, tmpg = g;
		g = max(g, a[i] + tmpf);
		f = max(f, b[i] + tmpg);
	//	f = max(tmpf, tmpg);
	//	g = max(tmpf, tmpg);
     //   cout << f << " " << g << endl;
	}
	cout << max(f, g) << endl;
}

