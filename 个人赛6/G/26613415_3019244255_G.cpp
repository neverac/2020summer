#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll a, b;
	cin >> a >> b;
	if(a == b) {
		cout << "1" << endl;
	}
	else
	{
		ll ans = a / b, cnt = 0;
		a -= ans * b;
		while(true) {
		if(a == 1) {
			ans += b;
			break;
		}
		if(b == 1) {
			ans += a;
			break;
		}
		cnt += b / a;
		b %= a;
		swap(a, b);
	}
	cout << ans + cnt << endl;
	}
	
	return 0;
}