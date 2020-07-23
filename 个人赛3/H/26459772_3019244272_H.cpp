#include <bits/stdc++.h>
using namespace std;
string s[100];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++) cin >> s[i];
		bool flag = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(s[i][j] == 'A') flag = true;
			}
		}
		if(!flag){
			cout << "MORTAL" << endl;
			continue;
		}
		else{
			bool aaa = true;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(s[i][j] == 'P') aaa = false;
				}
			}
			if(aaa){
				cout << 0 << endl;
				continue;
			}
			int ans = 4;
			for(int i = 0; i < n; i++){
				bool t = true;
				for(int j = 0; j < m; j++){
					if(s[i][j] == 'P') t = false;
				}
				if(t){
					if(i == 0 || i == n - 1) ans = min(ans, 1);
					else ans = min(ans, 2);
				}
			}
			for(int j = 0; j < m; j++){
				bool t = true;
				for(int i = 0; i < n; i++){
					if(s[i][j] == 'P') t = false;
				}
				if(t){
					if(j == 0 || j == m - 1) ans = min(ans, 1);
					else ans = min(ans, 2);
				}
			}
			for(int i = 0; i < n; i++){
				if(s[i][0] == 'A' || s[i][m - 1] == 'A'){
					if(i == 0 || i == n - 1) ans = min(ans, 2);
					else ans = min(ans, 3);
				}
			}
			for(int j = 0; j < m; j++){
				if(s[0][j] == 'A' || s[n - 1][j] == 'A'){
					if(j == 0 || j == m - 1) ans = min(ans, 2);
					else ans = min(ans, 3);
				}
			}			
			cout << ans << endl;
		}
	}
	return 0;
}