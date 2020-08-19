#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,pos;
}a[2010];
struct nodes{
	long long dis;
	int p1,p2;
}dd[4000100];
bool vis[2010];
bool cmp(nodes x,nodes y){
	return x.dis<y.dis;
}
long long getdis(int i,int j){
	return 1ll*(a[i].x-a[j].x)*(a[i].x-a[j].x)+1ll*(a[i].y-a[j].y)*(a[i].y-a[j].y)+1ll*(a[i].z-a[j].z)*(a[i].z-a[j].z);
}
int n;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[i]={x,y,z,i};
	}
	int cnt=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			long long d=getdis(i,j);
			dd[++cnt]={d,i,j};			
		}
	}
	sort(dd+1,dd+1+cnt,cmp);
	int tt=0;
	for (int i=1;i<=cnt;i++){
		if (!vis[dd[i].p1]&&!vis[dd[i].p2]){
			tt+=2;
			cout<<dd[i].p1<<" "<<dd[i].p2<<endl;
			vis[dd[i].p1]=1;
			vis[dd[i].p2]=1;
		}
		if (tt==n) break; 
	}
	return 0;
}