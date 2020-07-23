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
char s[65][65];
int cntl[65], cntr[65];
void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	memset(cntl, 0, sizeof(cntl));
	memset(cntr, 0, sizeof(cntr));
	//int ans = 0;
	int flag = 1, ff = 0;;
	rep(i,1,n) {
		scanf("%s", s[i] + 1);
		rep(j,1,m) {
			if (s[i][j] == 'A') cntl[i]++, cntr[j]++, flag = 0;
			if (s[i][j] == 'P') ff = 1;
		}
	}
	if (!ff) {
		puts("0");
		return;
	}
	if (flag) {
		puts("MORTAL");
		return;
	}
	if (cntl[1] == m || cntl[n] == m || cntr[1] == n || cntr[m] == n) {
		puts("1");
		return;
	}
	for (int i = 1; i <= n; i++) if (cntl[i] == m) {
		puts("2");
		return;
	}
	rep(i,1,m) if (cntr[i] == n) {
		puts("2");
		return;
	}
	if (s[1][1] == 'A' || s[1][m] == 'A' || s[n][1] == 'A' || s[n][m] == 'A') {
		puts("2");
		return ;
	}
	if (cntl[1] || cntl[n] || cntr[1] || cntr[m]) {
		puts ("3");
		return;
	}
	puts("4");
	return;


}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}

}