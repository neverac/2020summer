#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
map<string,int> mmp;
int n,m,cnt;
string ss;
struct node{
	string s;
	int l;
}no[1050];
bool cmp(node i, node j){
	return i.l<j.l;
}
int main(){
	IO
	cin >>m >> n;
	for(int i=1;i<=n;++i){
		cin >> ss;
		if(!mmp.count(ss)) {
			mmp[ss] = ++cnt;
			no[cnt].l = ss.length();
			no[cnt].s = ss;
		}
	}
	n = cnt;
	sort(no+1,no+n+1,cmp);
	int ans = 0;
	for(int i=1,l=0;i<=n;++i){
	    if(l+no[i].l<=m) ans ++;
	    l += 1+no[i].l;
	}
	cout << ans << endl;
	return 0;
}

