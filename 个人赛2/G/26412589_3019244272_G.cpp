#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
long long a[maxn];
int main(){
	long long n, k;
	cin >> n >> k;
	a[1] = 1;
	a[2] = 1 + k;
	for(int i = 3; i <= k + 1; i++){
		if(i & 1) a[i] = a[i - 2] + 1;
		else a[i] = a[i - 2] - 1;
	}
	for(int i = k + 2; i <= n; i++){
		a[i] = i;
	}
	for(int i = 1; i <= n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}