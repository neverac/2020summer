#include <bits/stdc++.h>
using namespace std;
int main(){
	long long sub=0, add=0;
	long long n;
	long long num = 0;
	int min=0;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0 ; i < n ; i++ ){
		switch (s[i]){
			case '-':num--;sub++;break;
			case '+':num++;add++;break;
		}
		if(num<min)min=num;
	}
	cout << -min-sub+add << endl ;
	
	
	return 0;
} 