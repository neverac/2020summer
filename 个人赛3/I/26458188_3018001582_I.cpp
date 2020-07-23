#include<bits/stdc++.h>
using namespace std;
int main() {
	char caozuo[100];
	int sum;
	cin >> sum;
	for (int i = 0; i < sum; i++) {
		cin >> caozuo[i];
	}
	for (int i = 0; i <= 100; i++) {
		int ans = i;
		for (int j = 0; j < sum; j++) {
			if (caozuo[j] == '+') ans++;
			else ans--;
			if (ans < 0) break;
		}
		if (ans >= 0) {
			cout << ans;
			break;
		}
	}
	return 0;
}