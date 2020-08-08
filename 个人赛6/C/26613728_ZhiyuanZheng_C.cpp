#include <bits/stdc++.h>
using namespace std;
int fa[100010];

int getfa(int x){
	if (fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	fa[x]=fa[y];
}
int main(){
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
	int ans=0;
	while (k--){
		int a,b;
		cin>>a>>b;
		int fx=getfa(a),fy=getfa(b);
		if (fx==fy) ans++;
		else {
			merge(fx,fy);
		} 
	}
	cout<<ans<<endl;
	return 0;
}

