#include <bits/stdc++.h>
using namespace std;
int n;
int a[100]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	} 
	bool ok=true;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++){
				if (i==j||j==k||i==k) continue;
				int x=a[i]-a[j];
				int t=x/a[k];
				if (t*a[k]!=x) ok=false;
			}
		}
	}
	if (ok) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}

