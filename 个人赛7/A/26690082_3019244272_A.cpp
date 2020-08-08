#include <bits/stdc++.h>
using namespace std;
char s[100000 + 10];
vector<int> a[256];
int main(){
	int k, n;
	cin >> k;
	cin >> (s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++){
		a[s[i]].push_back(i);
	}
	long long ans = 0;
	for(int i = 'a'; i <= 'z'; i++){
		for(int j = 1; j <= k; j++){
			if(a[i].size() < j) break;
			size_t p1 = 0, p2 = j - 1;
			while(p2 < a[i].size()){
				int l, r;
				if(p1 == 0) l = 1;
				else l = a[i][p1 - 1] + 1;
				if(p2 == a[i].size() - 1) r = n;
				else r = a[i][p2 + 1] - 1;
				ans += (long long)(a[i][p1] - l + 1) * (r - a[i][p2] + 1);
				p1++; p2++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}