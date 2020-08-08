#include <bits/stdc++.h>
using namespace std;
int n;
void does(long long x){
	while (x%2==0){
		x/=2;
	}
	long long a=1,b=1,c=1;
	long long sa=1,sb=1,sc=1;
	while (x%3==0){
		a*=3;
		sa+=a;
		x/=3;
	}
	while (x%5==0){
		b*=5;
		sb+=b;
		x/=5;
	}
	while (x%7==0){
		c*=7;
		sc+=c;
		x/=7;
	}
	long long tmp=sa*sb*sc;
	cout<<tmp<<endl;
}
int main(){
	cin>>n;
	while (n--){
		long long x;
		cin>>x;
		does(x);
	}
	return 0;
}

