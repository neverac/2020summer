#include <cstdio>
#include <iostream>
using namespace std;
int n,mx,now;
string s; 
int main(){
	cin >> n >> s;
	mx = 0;
	now = 0;
	for(int i = 0;i < n; ++ i){
		if(s[i] == '-') now --;
		else now ++;
		if(now < mx) mx = now;
	}
	cout << mx*(-1)+now <<endl;
	return 0;
}
