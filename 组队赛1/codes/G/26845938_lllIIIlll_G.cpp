#include <bits/stdc++.h>
using namespace std;
int n,a[100100];
int t[100100];
int z[100100],y[100100];
void add(int x)
{
	while (x<=100000)
	{
		t[x]++;
		x+=x&-x;
	}
}
int sum(int x)
{
    int ans=0;
    while (x)
	{
        ans+=t[x];
		x-=x&-x;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
        scanf("%d",&a[i]);
        add(a[i]);
        z[i]=sum(100000)-sum(a[i]);
    }
    memset(t,0,sizeof(t));
    for(int i=n;i>=1;i--)
	{
        add(a[i]);
        y[i]=sum(100000)-sum(a[i]);
    }
	long long ans = 0;
	for(int i=1;i<=n;i++)
	{
        ans=ans+min(z[i],y[i]);
    }
    cout<<ans<<endl;
	return 0;
}
 