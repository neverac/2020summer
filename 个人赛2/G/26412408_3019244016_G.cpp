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
	int n, k;
	set<int> s;
	cin >> n >> k;
	//if (k >= n-1) 
	vector<int>p;
	rep(i,2,n) s.insert(i);
	p.push_back(1);
	int cnt = 0;
	dow (i, k, 1) {
		int j;
        //cout << p[cnt]
		if (cnt & 1) j = p[cnt] - i;
		else j = p[cnt] + i;
		p.push_back(j);
		s.erase(j);
		cnt++;
	}
	while (!s.empty()) {
		p.push_back(*s.begin());
		s.erase(s.begin());
	}
	for(auto i:p) {
		printf("%d ", i);
	}
	cout << endl;
}