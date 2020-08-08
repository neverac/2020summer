#include <bits/stdc++.h>
using namespace std;
int T,n,p;
string s;
int main(){
	cin >> T;
	while (T --){
		cin >> n;
		// s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		string s = string(200, 'a');
		cout << s << endl;
		for (int i = 1; i <= n; ++ i) {
			cin >> p;
			if(s[p] == 'a') s[p] = 'b';
			else s[p] = 'a';
			cout << s << endl;
		}
	}
	return 0;
}