#include<iostream>
using namespace std;
int a[107],b[107],c[107][107];
int n,m,h;
int main()
{
	cin>>n>>m>>h;
	for(int i=1;i<=m;++i)cin>>b[i];
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(c[i][j]==0)cout<<"0 ";
			else cout<<min(a[i],b[j])<<" ";
		}
		cout<<endl;
	}
	return 0;
}