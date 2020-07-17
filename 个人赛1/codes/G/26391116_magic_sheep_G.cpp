#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 2e5+100;

int n,m,l1,l2,r,cnt;

long long a[maxn],b[maxn],ans;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+m,cmp);
	if(b[m]<a[1])
	{
		cout<<-1<<endl;
		return 0;
	}
	l1=1,l2=1;
	while(l1<=n)
	{
		if((cnt<m-1||a[l1]==b[l2])&&l2<=m) 
		{
			ans+=b[l2];
			cnt++,l2++;
		}
		else 
		{
			ans+=(m-cnt)*a[l1];l1++;cnt=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}