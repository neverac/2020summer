#include <cstdio> 
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=2E5+10;
int a[MAXN];
string s[MAXN];
char next(char x) {
	x=(x-'a'+1)%26+'a';
	return x;
}
int doing() {
	int n;
	cin>>n;
	for(int i=1;i<=n;++i) {
		cin>>a[i+1];
		s[i]="";
	}s[n+1]="";
	s[1]=string(100,'a');
	for(int i=2;i<=n+1;++i) {
		for(int j=0;j<100;++j) {
			if(j<a[i]) {
				s[i].push_back(s[i-1][j]);
			}else {
				s[i].push_back(next(s[i-1][j]));
			}
		}
	}
	for(int i=1;i<=n+1;++i) {
		cout<<s[i]<<endl;
	}
	return 0;
} 
int main() {
	int t;
	cin>>t;
	for(int i=1;i<=t;++i) {
		doing();
	}
	return 0;
}