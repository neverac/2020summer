#include<iostream>
#include<algorithm>
using namespace std;

int N[1001];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> N[i];
	}
	sort(N, N + n);
	int total = 0;
	for (int i = 0; i < k; i++) {
		total += N[i];
	}
	cout << total << endl;
	return 0;
}