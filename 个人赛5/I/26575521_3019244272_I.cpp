#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
string a, b, ans;
int main(){
	ll T;
	cin >> T;
	while(T--){
		cin >> s;
		a.clear(); b.clear(); ans.clear();
		for(size_t i = 0; i < s.length(); i++){
			if(s[i] & 1) a += s[i];
			else b += s[i];
		}
		size_t i = 0, j = 0;
		while(i < a.length() && j < b.length()){
			if(a[i] < b[j]) ans += a[i++];
			else ans += b[j++];
		}
		while(i < a.length()) ans += a[i++];
		while(j < b.length()) ans += b[j++];
		cout << ans << endl;
	}
	return 0;
}