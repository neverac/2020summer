#include <vector>
#include <iostream>
using namespace std;
int main(){
	int n;
	vector<int> a, b;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		a.push_back(x);
	}
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		b.push_back(x);
	}
	int i = 0, j = 0;
	while(i < n && j < n){
		while(i < n && a[i] < b[j]) i++;
		while(j < n && a[i] > b[j]) j++;
	}
	int ans = max(n - i, n - j);
	cout << ans << endl;
	return 0;
}