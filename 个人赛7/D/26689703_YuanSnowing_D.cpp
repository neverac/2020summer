#include <bits/stdc++.h>
using namespace std;
long long a,b,c,n,T,ans;
int main(){
	cin >> T;
	while(T --){
		cin >> n;
		a=3ll;
		b=5ll;
		c=7ll;
		while(n%2ll==0) n/=2ll;
		while(n%3ll==0) n/=3ll,a*=3ll;
		while(n%5ll==0) n/=5ll,b*=5ll;
		while(n%7ll==0) n/=7ll,c*=7ll;
		a --;
		a /= 2ll;
		b --;
		b /= 4ll;
		c --;
		c /= 6ll;
		cout << a*b*c <<endl;
	}
	return 0;
}
