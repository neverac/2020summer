#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y,s;
}f[100010];
int num[110][110][12],sum[110][110][12];
int n,q,c;
int main(){
	cin>>n>>q>>c;
	for (int i=1;i<=n;i++){
		cin>>f[i].x>>f[i].y>>f[i].s;
		num[f[i].x][f[i].y][f[i].s]++;
	}
	memset(sum,0,sizeof sum);
	for (int i=1;i<=100;i++){
		for (int j=1;j<=100;j++){
			for (int k=0;k<=c;k++){
				sum[i][j][k]=sum[i][j-1][k]+sum[i-1][j][k]-sum[i-1][j-1][k]+num[i][j][k];
			}
		}
	}
	while (q--){
		int ti,x1,y1,x2,y2;
		cin>>ti>>x1>>y1>>x2>>y2;
		long long ans=0;
		for (int k=0;k<=c;k++){
			ans=ans+(((ti+k)%(c+1))*(sum[x2][y2][k]-(sum[x2][y1-1][k]+sum[x1-1][y2][k]-sum[x1-1][y1-1][k])));	
		}	
		cout<<ans<<endl;
	}
	return 0;
}
