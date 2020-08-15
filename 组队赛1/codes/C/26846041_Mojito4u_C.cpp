#include <bits/stdc++.h>
using namespace std;
int r,s,p;
vector <int> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>r>>s>>p;
	for (int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		int row=r-x+1,line;
		if (y<=s) line=s-y+1;
		else line=y-s;
		v.push_back(line+row);
	}
	sort(v.begin(),v.end());
	int ans=0;
	int k=0;
	for (int i=v.size()-1;i>=0;i--){
		ans=max(ans,v[i]+k);
		k++;
	}
	cout<<ans<<endl;
	return 0;
}

