#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
	IO;
	int T;
	cin>>T;
	while (T--){
		long long n,m,x,y;
		cin>>n>>m>>x>>y;
		if (y>=x){
			cout<<m<<endl;
		}else {
			cout<<min(m,(n+(m-1)*y)/x)<<endl;
		}
	}
	return 0;
}

