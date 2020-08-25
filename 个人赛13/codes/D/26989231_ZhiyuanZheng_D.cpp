#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
struct node{
	int u,v;
}a[200100];
int n,m;
bool cmp(node x,node y){
	if (x.v==y.v) return x.u<y.u;
	return x.v<y.v;
}
int fa[100100];
int ans[100100];
int getfa(int x){
	if (x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
int main(){
	IO;
	cin>>n>>m;
	for (int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		if (u>v) swap(u,v);
		a[i]={u,v};
	}
	sort(a+1,a+1+m,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int fx=getfa(a[i].u),fy=getfa(a[i].v);
		if (fx!=fy){
			fa[fx]=fy;
			ans[a[i].u]++;
			ans[a[i].v]++;
		}
	}
	int maxx=0;
	for (int i=1;i<=n;i++) maxx=max(maxx,ans[i]);
	cout<<maxx<<endl;
	return 0;
}

