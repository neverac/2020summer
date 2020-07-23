#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5+100;

int n,m;
char s[maxn];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='+') ans++;
		else ans--;
		if(ans<0) ans= 0;
	}
	cout<<ans<<endl;
	return 0;
}