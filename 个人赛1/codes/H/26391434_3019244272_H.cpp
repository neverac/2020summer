#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int num[maxn];
vector<int> id[maxn];
int p[maxn][5];
int a[maxn];
int vis[maxn];
bool In(int x, int q){
	for(int i = 1; i <= 3; i++){
		if(p[q][i] == x) return true;
	}
	return false;
}
int pick(int q){
	for(int i = 1; i <= 3; i++){
		if(!vis[p[q][i]]) return p[q][i];
	}
	return -1;
}
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n - 2; i++){
		cin >> p[i][1] >> p[i][2] >> p[i][3];
		num[p[i][1]]++;
		num[p[i][2]]++;
		num[p[i][3]]++;
		id[p[i][1]].push_back(i);
		id[p[i][2]].push_back(i);
		id[p[i][3]].push_back(i);
	}
	int st;
	for(int i = 1; i <= n; i++){
		if(num[i] == 1){
			st = i;
			break;
		}
	}
	int t = id[st][0];
	for(int i = 1; i <= 3; i++){
		a[num[p[t][i]]] = p[t][i];
		vis[p[t][i]] = 1;
	}
	for(int i = 4; i <= n; i++){
		for(int j = 1; j <= num[a[i - 2]]; j++){
			if(In(a[i - 1], id[a[i - 2]][j - 1])){
				int t = pick(id[a[i - 2]][j - 1]);
				if(t != -1){
					a[i] = t;
					vis[t] = 1;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << a[i] << ' ';
	} 
	cout << endl;
	return 0;
}