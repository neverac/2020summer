#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a, b, ans = 0;
	cin >> a >> b;
	while(a && b){
		if(a >= b){
			ans += a / b;
			a %= b;
		}
		else{
			ans += b / a;
			b %= a;
		}
	}
	cout << ans << endl;
	return 0;
}