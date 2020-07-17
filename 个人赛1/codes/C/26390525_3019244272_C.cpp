#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, q[maxn], a[maxn];
set<int> s;
set<int>::iterator it;
void work(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> q[i];
	}
	for(int i = 1; i <= n; i++){
		if(q[i] < i || q[i] < q[i - 1]){
			cout << -1 << endl;
			return;
		}
	}
	s.clear();
	for(int i = 1; i <= n; i++){
		s.insert(i);
	}
	for(int i = 1; i <= n; i++){
		it = s.find(q[i]);
		if(it == s.end()) it = s.begin();
		a[i] = *it;
		s.erase(it);
	}
	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
int main(){
	int T;
	cin >> T;
	while(T--) work();
	return 0;
}