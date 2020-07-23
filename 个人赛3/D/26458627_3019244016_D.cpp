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
const int N = 5005;

int cnt[3];
vector<int> ans;
int main() {
	int n;
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	if (!cnt[1]) {
		rep(i,1,n) cout << 2 << " " ; cout << endl;
		return 0;
	}
	if (!cnt[2]) {
		rep(i,1,n) cout << 1 << " " ; cout << endl;
		return 0;
	}
	ans.push_back(2); cnt[2]--;
	int sum = 2;
	for (int i = 2; i <= n; i++) {
		if (sum % 2 == 0) {
			if (cnt[1]) {
				ans.push_back(1);
                sum += 1;
				cnt[1]--;
			}
			else ans.push_back(2), cnt[2]--, sum += 2;
		}
		else {
			if (cnt[2]) {
				ans.push_back(2);
				cnt[2]--;
                sum += 2;
			}
			else ans.push_back(1), cnt[1]--, sum+=1;
		}
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " " ; cout << endl;
}