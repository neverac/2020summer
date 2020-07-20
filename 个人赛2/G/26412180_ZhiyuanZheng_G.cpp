#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	cin>>n>>k;
	int l=1,r=n;
	cout<<l<<" ";
	l++;
	bool flag=true;
	while (k!=1){
		if (flag){
			k--;
			cout<<r<<" ";
			r--;
			flag=false;
		}else{
			k--;
			cout<<l<<" ";
			l++;
			flag=true;
		}
	}
	if (flag){
		for (int i=l;i<=r;i++) cout<<i<<" ";
	}else{
		for (int i=r;i>=l;i--) cout<<i<<" ";
	}
	cout<<endl;
	
	return 0;
}