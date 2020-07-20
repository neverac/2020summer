#include <bits/stdc++.h>
using namespace std;
bool a[310][310];

void does(int i,int j,int x){
	if (x==0){
		a[i][j-1]=true;
		a[i-1][j-1]=true;
		a[i+1][j-1]=true;
	}
	if (x==1){
		a[i-1][j]=true;
		a[i-1][j-1]=true;
		a[i-1][j+1]=true;
	}
	if (x==2){
		a[i][j+1]=true;
		a[i-1][j+1]=true;
		a[i+1][j+1]=true;
	}
	if (x==3){
		a[i+1][j]=true;
		a[i+1][j-1]=true;
		a[i+1][j+1]=true;
	}
}
void build(int num,int i,int j){
	bool t[4];
	memset(t,false,sizeof t);
	if (num&1) t[0]=true;
	if (num&2) t[1]=true;
	if (num&4) t[2]=true;
	if (num&8) t[3]=true;
	for (int x=0;x<4;x++){
		if (t[x]) does(i*2,j*2,x);
	}
}
int maxx=0,nu=0;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
void dfs(int x,int y){
	if (x%2==0&&y%2==0) nu++;
	a[x][y]=true;
	for (int i=0;i<4;i++){
		if (!a[x+dx[i]][y+dy[i]]) dfs(x+dx[i],y+dy[i]);
	}
} 
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int num;
			cin>>num;
			build(num,i,j);
		}
	}
	int cnt=0;
	for (int i=1;i<=2*n+1;i++){
		for (int j=1;j<=2*m+1;j++){
//			if (a[i][j]) cout<<"#";else cout<<" ";
			if (!a[i][j]) cnt++,nu=0,dfs(i,j),maxx=max(maxx,nu);
		}
//		cout<<endl;
	}
	cout<<cnt<<endl;
	cout<<maxx<<endl;
	return 0;
}

