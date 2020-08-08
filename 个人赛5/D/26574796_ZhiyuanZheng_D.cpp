#include <bits/stdc++.h>
using namespace std;
long long n,k;

int main(){
	int T;
	cin>>T;
	while (T--){
		cin>>n>>k;
		long long t=k/(n-1);
		if (k%(n-1)==0){
			cout<<t*n-1<<endl;
		}else
			cout<<t*n+(k%(n-1))<<endl;		
	}
	return 0;
}

