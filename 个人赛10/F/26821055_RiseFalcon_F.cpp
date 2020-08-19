#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1E7+10;
const int MD=31;
LL ch[MAXN][2],tot=1,root=1;
void insert(LL x) {
	int root=1;
	for(int i=MD;i>=0;--i) {
		LL v=(x>>i)&1;
		if(ch[root][v]==0) {
			ch[root][v]=++tot;
		}root=ch[root][v];
	}
}
LL dfs(LL now,LL dep) {
	if(now==0||dep<0)return 0;
	if(ch[now][0]==0&&ch[now][1]!=0) {
		return dfs(ch[now][1],dep-1);
	}
	if(ch[now][0]!=0&&ch[now][1]==0) {
		return dfs(ch[now][0],dep-1);
	}
	LL v=min(dfs(ch[now][0],dep-1),dfs(ch[now][1],dep-1))+(1LL<<dep);
//	cout<<v<<endl;
	return v;
} 
int main() {
	int n;cin>>n;
	for(int i=1;i<=n;++i) {
		LL x;cin>>x;insert(x);
	}
	//cout<<tot<<endl;
	cout<<dfs(root,MD)<<endl;
	return 0;
}