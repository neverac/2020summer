#include <bits/stdc++.h>
using namespace std;
struct word{
	string w;
	int n;
}s[1100];
bool cmp(word x, word y){
	if(x.n < y.n) return true;
	if(x.n == y.n && x.w < y.w) return true;
	return false;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= m; ++i) {
		cin>>s[i].w;
		s[i].n = s[i].w.size();
	}
	sort(s+1, s+m+1, cmp);
	int cnt = 0, ans = 0;
	for(int i = 1; i <= m; ++i){
		if(i < m && s[i].w == s[i+1].w) continue;
		if(cnt + s[i].n <= n) {++ans; cnt += s[i].n + 1;}
		else break;
	}
	cout<<ans<<endl;
	return 0;
}