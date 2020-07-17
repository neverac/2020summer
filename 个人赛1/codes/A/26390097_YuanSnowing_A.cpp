#include<bits/stdc++.h>
using namespace std;
int a[1005],n,k,tot;
int main(){
	cin >> n >> k;
	for (int i = 0;i < n; ++ i){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = 0;i < k; ++ i){
		tot += a[i];
	}
	cout << tot<< endl;
	return 0;
} 