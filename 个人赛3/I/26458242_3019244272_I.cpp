#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '+') ans++;
		else{
			ans = max(0, ans - 1);
		}
	}
	cout << ans << endl;
	return 0;
}