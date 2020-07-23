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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int mn = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '+') cur++;
		else cur--;
		mn = min(cur, mn);
	}
	if (mn < 0) mn = -mn;
	cout << cur + mn << endl;
}