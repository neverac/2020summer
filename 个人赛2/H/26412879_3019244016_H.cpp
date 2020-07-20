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
/*

cnt1 cnt2, 
x, y;

n / x + n / y - n/x/y;

n - n / x > cnt1;
n - n / y > cnt2;
n - n/x/y > cnt1 + cnt2
*/

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	long long n;
	n = max(a, b);
	ll l = n, r = 1000000000000000000ll;

	while (l < r) {
		ll mid = (l + r) >> 1;
		if (mid - mid / c < a || mid - mid / d < b || mid - mid/c/d < a + b) l = mid + 1;
		else r = mid;
	}
	n = l;
	cout << n << endl; 

}