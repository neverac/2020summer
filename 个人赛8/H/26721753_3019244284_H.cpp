#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+100;
int a[maxn];
int dp[maxn];
int np[maxn];
int n;

inline void dfs(int &i,int &cnt)
{
	if(i==n) 
	{
		dp[n]=1;
		i+=1;
		return ;
	}
	int ant=cnt,j=i;
	if(a[i+1]>a[i]) 
	  dfs(i+=1,cnt+=1);
	else i+=1;
	dp[j]=cnt-ant+1;
}
inline void dfs1(int &i,int &cnt)
{
	if(i==1)
	{
		np[i]=1;
		i-=1;
		return ;
	}
	int ant=cnt,j=i;
	if(a[i-1]<a[i]) 
	 dfs1(i-=1,cnt+=1);
	else i-=1;
	np[j]=cnt-ant+1;
}
int main()
{
	cin>>n;
	int _max=0;
	a[n+1]=a[0]=0;
	for(int i=1;i<=n;i++)
	    cin>>a[i]; 
	int cnt;
	for(int i=1;i<=n;) 
	  dfs(i,cnt=0);
	for(int i=n;i>=1;) 
	  dfs1(i,cnt=0);
	for(int i=1;i<=n;i++) 
	 _max=max(_max,dp[i]);
	for(int i=2;i<n;i++) 
	 if(a[i-1]<a[i+1]) 
	  _max=max(_max,np[i-1]+dp[i+1]);
	cout<<_max<<endl;
	return 0;
} 
