#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int a[maxn], b[maxn];
int main(){
	int n;
	cin >> n;
	int ones = 0, twos = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 1) ones++;
		else twos++;
	}
	if(ones && twos){
		cout << 2 << ' ' << 1 << ' ';
		for(int i = 1; i < twos; i++) cout << 2 << ' ';
		for(int i = 1; i < ones; i++) cout << 1 << ' ';
	}
	else{
		for(int i = 1; i <= n; i++){
			cout << a[i] << ' ';
		}
	}
	cout << endl;
	return 0;
}

/*
2 3 5 6 7
4ge
*/

/*
2 3 5 6 7 8 9 10 11
5ge

1 2 3 5 6 7 8 10 11
*/