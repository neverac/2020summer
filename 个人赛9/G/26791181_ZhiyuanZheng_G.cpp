#include<bits/stdc++.h>
using namespace std;
set<int> s[4];
int a[200100];
int n,m;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		s[x].insert(a[i]);
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		s[x].insert(a[i]);
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		if(s[x].size()==0) cout<<-1<<" ";
		else{
			int now=*(s[x].begin());
			cout<<now<<" ";
			for (int ii=1;ii<=3;ii++)
				if(s[ii].find(now)!=s[ii].end()) s[ii].erase(now);
		}
	}
	cout<<endl;
	return 0;
}