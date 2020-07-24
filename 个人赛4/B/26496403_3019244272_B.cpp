#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin >> s;
	int n = 0;
	for(int i = max(0, (int)s.length() - 2); i < s.length(); i++){
		n = n * 10 + s[i] - '0';
	}
	if(n % 4) cout << 0 << endl;
	else cout << 4 << endl;
	return 0;
}
/*
1 1 1 1 4
1 2 3 4 0
1 4 9 16 0
1 8 27 64 0
1 = 1
16 = 1
81 = 1
256 = 1
*/