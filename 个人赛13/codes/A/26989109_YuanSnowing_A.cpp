#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long long T,n,m,x,y,j;
int main(){
	IO
	cin >> T;
	while(T --){
		cin >>n >> m >> x >> y;
		long long ans = 0;
		j = x-y;
		if(j <= 0) ans = m;
		else{
			ans = min(m,(n+(m-1)*y)/x);
		}
		cout <<ans <<endl;
	}
	return 0;
}

