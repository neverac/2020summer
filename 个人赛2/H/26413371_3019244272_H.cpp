#include <bits/stdc++.h>
using namespace std;
int main(){
	long long c1, c2, x, y;
	cin >> c1 >> c2 >> x >> y;
	long long l = 0, r = 1LL << 60, mid, ans;
	while(l <= r){
		mid = l + r >> 1;
		long long s1, s2, s12;
		s1 = mid / x;
		s2 = mid / y;
		s12 = mid / (x * y);
		long long r1 = max(0LL, c1 - s2 + s12), r2 = max(0LL, c2 - s1 + s12);
		if(r1 + r2 <= mid - s1 - s2 + s12){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}
/*
c1 = 3 c2 = 1 x = 2 y = 3
mid = 5
s1 = mid / 2 = 2
s2 = mid / 3 = 1
s3 = 0
r1 = max(0, 3 - 1 + 0) = 2
r2 = max(
*/

/*
1: mid - s1
2: mid - s2
12: mid - s1 - s2 + s3

only 1: s2 - s3
only 2: s1 - s3

/*

tot = mid - s1 - s2 + s3

*/