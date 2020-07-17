
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



void solve() {
	int n;
	cin >> n;
	vector<int>a(n);
	queue<int>q;
	vector<int>p(n);
	cin >> p[0];
	int cnt = 1;
    int mx = p[0];
	while (cnt < p[0]) q.push(cnt), cnt++;
	cnt = p[0] + 1;
	rep(i,1,n-1) {
   // cout << i  << "  " << n-1 << " ? " << endl;
    
		int x;
		cin >> x;
       // cout << x << " " << p[i-1] << endl;
		if (x > mx) {
			p[i] = x;
            mx = x;
			while (cnt < p[i]) q.push(cnt), cnt++;
			cnt++;
		}
        else if (x < p[i-1]) {
      
            rep(j,i+1,n-1) cin >> x;
            cout << "-1\n";return;
            }
		else {
			if (!q.empty()) {
            
				p[i] = q.front(); q.pop();
              //  cout << p[i] << " " << i << endl;
			}
				else {
               
                    rep(j,i+1, n-1) cin >> x;
					cout << "-1\n";
					return ;
				}
			
		}
	}
	rep(i,0,n-1) cout << p[i] << " " ; 
    cout << endl;
	return; 
}

int main() {
	ios::sync_with_stdio(0);
    int t;
	cin >> t;
	while (t--) {
		solve();
	}
}