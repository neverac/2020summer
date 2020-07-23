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



void solve() {
	int n;
	long long s;
	scanf("%d %lld", &n, &s);
	vector<pi>r(n);
	int mn = 0;
	rep(i,0,n-1) {
		scanf("%d %d", &r[i].fi, &r[i].se);
		s-=r[i].fi;
		mn =max(r[i].se, mn);
	}
	sort(r.begin(), r.end());
	int L = r[(n-1)/2].fi, R = mn;
	while (L < R) {
		int mid = (L+ R + 1) >> 1;
		int cnt = 0;
		long long c = 0;
		dow(i,n-1,0) {
			if (r[i].se >= mid) {
				cnt++;
				if (r[i].fi < mid) c += mid - r[i].fi;
			}
            if (cnt == n / 2 + 1) break;
		}
		if (c <= s && cnt == n / 2 + 1) L = mid;
		else R = mid - 1;
	}
	printf("%d\n", L);

}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
