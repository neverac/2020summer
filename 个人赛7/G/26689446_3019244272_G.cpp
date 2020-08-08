#include <vector> 
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
char s[1000 + 10][1000 + 10];
vector<int> p[1000 + 10];
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> (s[i] + 1);
		for(int j = 1; j <= m; j++){
			if(s[i][j] == '1') p[i].push_back(j);
		}
	}
	int ans = 100000;
	vector<int>::iterator it;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i][j] == '2'){
				for(int k = 1; k <= n; k++){
					it = lower_bound(p[k].begin(), p[k].end(), j);
					if(it != p[k].end()) ans = min(abs(k - i) + *it - j, ans);
					if(it != p[k].begin()){
						--it;
						ans = min(abs(k - i) + j - *it, ans);
					}
				}
			}
		}
	}
	cout << ans + 1 << endl;
	return 0;
}