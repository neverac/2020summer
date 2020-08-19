#include <bits/stdc++.h>
using namespace std;
int a[26][200100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int l=s.size();
	for (int i=0;i<l;i++){
		for (int j=0;j<26;j++){
			if (s[i]-'a'==j)
				a[j][i+1]=a[j][i]+1;
			else a[j][i+1]=a[j][i];
		}
	}
	int q;
	cin>>q;
	while (q--){
		int l,r;
		cin>>l>>r;
		if (l==r) {
			cout<<"Yes"<<endl;	
			continue;
		}
		if (s[l-1]!=s[r-1]){
			cout<<"Yes"<<endl;
			continue;
		}
		int k=0,ll=0;
		for (int i=0;i<26;i++){
//			if (a[i][r]-a[i][l-1]>1) k++;
			if (a[i][r]-a[i][l-1]>0) ll++;
		}
		if (ll>2) cout<<"Yes"<<endl;else cout<<"No"<<endl;
	}
	return 0;
}

