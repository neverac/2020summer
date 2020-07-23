#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin>>n;
	string s;
	cin>>s;
	int ans=0;
	for (int i=0;i<n;i++){
		if (s[i]=='-'){
			if (ans>0) ans--;
		}else ans++;
	}
	cout<<ans<<endl;
	return 0;
} 