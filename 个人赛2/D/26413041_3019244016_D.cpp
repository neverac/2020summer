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
n - n / x - n/ y + n/x/y > cnt1 + cnt2
*/
void solve() {
	double p[3][2];
	rep(i,0,2)  scanf("%lf%lf", &p[i][0], &p[i][1]);
    if (p[1][0] > p[2][0]) swap(p[1], p[2]);
	double a[3], b[2];
	double m[3][4];
	rep(i,0,2) {
		m[i][0] = p[i][0] * p[i][0];
		m[i][1] = p[i][0];
		m[i][2] = 1;
		m[i][3] = p[i][1];
	}
   // rep(i,0,2) {rep(j,0,3) cout << m[i][j] << " " ; cout << endl;}
	rep(i,0,2) {
		int t = i;
		while (m[t][i] == 0) t++;
		rep(j,0,3) swap(m[t][j], m[i][j]);
		rep(j,i+1,2) {
			double c = m[j][i] / m[i][i];
            //cout << c << endl;
			rep(k,i,3) {
				m[j][k] -= c * m[i][k];
			}
		}
       //  rep(ii,0,2) {rep(jj,0,3) cout << m[ii][jj] << " " ; cout << endl;} cout << endl;
	}
   // rep(i,0,2) {rep(j,0,3) cout << m[i][j] << " " ; cout << endl;}
	a[2] = m[2][3] / m[2][2];
	a[1] = (m[1][3]-m[1][2] * a[2]) / m[1][1];
	a[0] = (m[0][3]-m[0][2] * a[2] - m[0][1] * a[1]) / m[0][0];
   // cout << a[2] << " " << a[1] << " " << a[0] << endl;
	//reverse(a, a + 3);
	swap(a[0],a[2]);
	b[0] = (p[2][1] - p[1][1]) / (p[2][0] - p[1][0]);
	b[1] = p[2][1] - b[0] * p[2][0];
	//reverse(b, b + 2);
	swap(b[0], b[1]);
	// for (i = p1 -> p2) /integ{ax^2 + bx + c}dx
    // 1/5 * x * 2 + 2 x
	a[1] -= b[1], a[0] -= b[0];
	a[2] = a[2] / 3 * (p[2][0] * p[2][0] * p[2][0] - p[1][0] * p[1][0] * p[1][0]);
	a[1] = a[1] / 2 * (p[2][0] * p[2][0] - p[1][0] * p[1][0]);
	a[0] = a[0] * (p[2][0] - p[1][0]);
	printf("%.2lf\n",abs(a[0] + a[1] + a[2]));

}




int main() {
	int t;
	scanf("%d", &t);
	while(t--) solve();
}