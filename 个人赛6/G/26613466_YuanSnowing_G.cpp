#include<bits/stdc++.h>
using namespace std;
long long a,b; 
int main(){
	long long ans=0;
	cin >> a >> b;
	ans += a/b;
	a %= b;
	while(a){
		if(a == 1){
			ans += b;
			break;
		}
		if(b>a)swap(a,b);
		ans += a/b;
		a %= b;
		if(b>a)swap(a,b);
	}
	cout << ans <<endl;
    return 0;
}