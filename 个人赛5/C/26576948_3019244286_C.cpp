#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

long long day[400];

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) 
		scanf("%d", day + i);
	day[t] = -1;
	long long money = 100;
	long long x = 0;
	for (int i = 0; i < t; ++i) {
		if (day[i] <= day[i + 1]) {
			x += money / day[i];
			money %= day[i];
			if (x >= 100000) {
				money += (x - 100000) * day[i];
				x = 100000;
			}
		}
		else {
			money += x * day[i];
			x = 0;
		}
	}
	printf("%lld\n", money);
	return 0;
}