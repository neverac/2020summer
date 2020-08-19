#include <bits/stdc++.h>
using namespace std;
long long a[100010];
int n;
vector <int> aa;
int dfs(vector<int> now,int tmp){
	if (tmp==-1||now.size()==0){
		return 0;	
	}
	vector<int> x,y;
	x.clear();
	y.clear();
	int tt=(1<<tmp);
	for (int i=0;i<now.size();i++){
		if (tt&now[i]) x.push_back(now[i]);
		else y.push_back(now[i]);
	}
	int ans1=2e9,ans2=2e9;
	if (x.size()!=0) ans1=dfs(x,tmp-1);
	if (y.size()!=0) ans2=dfs(y,tmp-1);
	int ans=min(ans1,ans2);	
	if (x.size()!=0&&y.size()!=0) ans+=tt;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		aa.push_back(a[i]);
	}
	cout<<dfs(aa,30)<<endl;
	return 0;
}

