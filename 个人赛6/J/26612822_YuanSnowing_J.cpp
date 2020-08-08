#include<bits/stdc++.h>
using namespace std;
int n,k,a,s;
int main(){
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> a;
		if(a%k == 0){
			a /= k;
		}else{
			a /= k;
			a ++;
		}
		s += a;
	}
	if(s%2==0) s/=2;
	else {
		s/=2;
		s ++;
	}
	cout << s <<endl;
    return 0;
}