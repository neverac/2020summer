#include<bits/stdc++.h>
using namespace std;
struct {
	int x,y,z;
}a[2005];
struct node{
	int p1,p2;
	long long d;
}dis[2005*2005];
bool vis[2005];
bool cmp(node x,node y){
	return x.d<y.d;
}
int n,cnt;
int main(){
	cin >> n;
	for (int i = 1,x,y,z; i <= n;++ i){
		cin >> x >> y >> z;
		a[i] = {x,y,z};
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = i+1; j <= n; ++ j){
			dis[++cnt]={i,j,
			(long long)(a[i].x-a[j].x)*(long long)(a[i].x-a[j].x)+
			(long long)(a[i].y-a[j].y)*(long long)(a[i].y-a[j].y)+
			(long long)(a[i].z-a[j].z)*(long long)(a[i].z-a[j].z)};			
		}
	}
	sort(dis+1,dis+cnt+1,cmp);
	for (int i = 1; i <= cnt; ++ i){
		if (!vis[dis[i].p1] && !vis[dis[i].p2]){
			n -= 2;
			cout << dis[i].p1 << " " << dis[i].p2 << endl;
			vis[dis[i].p1] = 1;
			vis[dis[i].p2] = 1;
		}
		if (!n) break; 
	}
	return 0;
}