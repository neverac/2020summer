#include <bits/stdc++.h>
using namespace std;
string s, name, num;
map<string, int> mp;
int scnt;
int root[100], tr[1000000][10], val[1000000], fa[1000000], son[1000000], mark[1000000], tcnt;
void insert(int u, string nu){
	for(int i = nu.length() - 1; ~i; i--){
		int v = nu[i] - '0';
		if(!tr[u][v]){
			tr[u][v] = ++tcnt;
			fa[tcnt] = u;
			val[tcnt] = v;
		}
		son[u] = true;
		u = tr[u][v];
	}
	mark[u] = 1;
}
queue<int> q;
void print(int root){
	int ans = 0;
	q.push(root);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(mark[u] == 1 && son[u] == 0){
			ans++;
		}
		else{
			for(int v = 0; v < 10; v++){
				if(tr[u][v]){
					q.push(tr[u][v]);
				}
			}
		}
	}
	cout << ans << ' '; 
	q.push(root);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(mark[u] == 1 && son[u] == 0){
			for(int t = u; mark[t] != -1; t = fa[t]){
				cout << val[t];
			}
			cout << ' ';
		}
		else{
			for(int v = 0; v < 10; v++){
				if(tr[u][v]){
					q.push(tr[u][v]);
				}
			}
		}
	}
	cout << endl;
}
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> name;
		if(!mp.count(name)){
			mp[name] = ++scnt;
			root[scnt] = ++tcnt;
			mark[tcnt] = -1;
		}
		int x;
		cin >> x;
		while(x--){
			cin >> num;
			insert(root[mp[name]], num);
		}
	}
	cout << mp.size() << endl;
	map<string, int>::iterator it;
	for(it = mp.begin(); it != mp.end(); ++it){
		cout << it -> first << ' ';
		print(root[it -> second]);
	}
}