#include<bits/stdc++.h>
using namespace std;
int main() {
	long long int money = 100;
	int day; cin >> day;
	long long int past_price,now_price;
	cin >> past_price;
	for (int i = 1; i < day; i++) {
		cin >> now_price;
		if (now_price > past_price) {
			if (money > 100000 * past_price) {
				money += 100000 * (now_price - past_price);
			}
			else {
				money += (money / past_price)*(now_price - past_price);
			}
		}
		past_price = now_price;
	}
	printf("%lld", money);
	return 0;
}