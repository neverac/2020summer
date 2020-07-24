#include <bits/stdc++.h>
using namespace std;
string str;
multiset<int> s;
multiset<int>::iterator it;
int main(){
	int t, n, x;
	cin >> t;
	while(t--){
		cin >> n >> x >> str;
		s.clear();
		int sum = 0, ans;
		for(int i = 0; i < n; i++){
			if(str[i] == '1'){
				sum--;
			}
			else sum++;
			s.insert(sum);
		}
		if(sum < 0){
			ans = 0;
			it = s.begin();
			while(it != s.end()){
				if(*it - x >= 0 && (*it - x) % sum == 0) ans++;
				++it;
			}
		}
		else if(sum == 0){
			if(s.count(x)){
				cout << -1 << endl;
				continue;
			}
			else //cout << 0 << endl;
				ans = 0;
		}
		else{
			ans = 0;
			it = s.begin();
			while(it != s.end()){
				if((x - *it) >= 0 && (x - *it) % sum == 0) ans++;
				++it;
			}
		//	cout << ans << endl;
		}
		if(!x) ans++;
		cout << ans << endl;
	}
	return 0;
}
