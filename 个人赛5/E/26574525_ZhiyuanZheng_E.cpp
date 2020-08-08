#include <bits/stdc++.h>
using namespace std;
const int maxn=200010;
int nxt[7000010][2];
int a[maxn];
int n;
int tt;
long long ans;
void add(int x){
	int now=0;
	for (int i=29;i>=0;i--){
		int t=(x>>i)&1;
		if (nxt[now][t]==0){
			nxt[now][t]=++tt;
		}
		now=nxt[now][t];
	}
}
int query(int x){
	int tmp=0,now=0;
	for (int i=29;i>=0;i--){
		int t=(x>>i)&1;
		if (nxt[now][t]){
			now=nxt[now][t];
		}else{
			now=nxt[now][t^1];
			tmp=tmp|(1<<i);
		}
	}
	return tmp;
}
void dfs(int l,int r,int d){
	if (d==-1||l>=r) return;
	int mid=l-1;
	while (mid<r&&!(a[mid+1]>>d&1)) mid++;
	dfs(l,mid,d-1);
	dfs(mid+1,r,d-1);
	if (mid==l-1||mid==r) return;
	for (int i=l;i<=mid;i++){
		add(a[i]);
	}
	int inf=1e9;
	for (int i=mid+1;i<=r;i++){
		inf=min(inf,query(a[i]));
	}
	ans+=inf;
	for (int i=0;i<=tt;i++){
		nxt[i][0]=nxt[i][1]=0;
	}
	tt=0;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,n,29);
	cout<<ans<<endl;
	return 0;
} 