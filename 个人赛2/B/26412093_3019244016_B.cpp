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
	int a, b, c, d;
	while (scanf("%d", &a) && a) {
		scanf("%d%d%d", &b, &c, &d);
		vector<int>vis(65540), A;
		vector<int>cnt(40);
		A.push_back(d);
		int n = 0;
		while (!vis[A[n]]) {
			vis[A[n]] = 1;
			A.push_back((1ll * A[n] * a + b) % c);
            n++;
		}
		A.pop_back();
		rep(i,0,n-1) {
            //cout << A[i] << " ";
			rep(j,0,15) {
				if (A[i] & (1 << j)) cnt[j]++;
			}
		}
        //cout << endl;
		string s;
		rep(i,0,15) {
            s.push_back(0);
			if (cnt[i] == 0) s[i] = '0';
			else if (cnt[i] == n) s[i] = '1';
			else s[i] = '?';
		}
        reverse(s.begin(),s.end());
		cout << s << endl;
	}
}