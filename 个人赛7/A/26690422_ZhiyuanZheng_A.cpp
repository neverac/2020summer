#include <bits/stdc++.h>
using namespace std;
vector <int> a[26];
int k;
int main(){
	string s;
	cin>>k;
	cin>>s;
	long long ans=0;
	int l=s.size();
	for (int i=0;i<26;i++){
			for (int j=0;j<l;j++){
				if (s[j]-'a'==i)
					a[s[j]-'a'].push_back(j+1);	
				int t=a[i].size();
				if (t==0) continue;
				if (t<=k) ans+=a[i][t-1];
				if (t>k) ans+=a[i][t-1]-a[i][t-1-k];
			}	
	}
	cout<<ans<<endl;
	
	return 0;
}

