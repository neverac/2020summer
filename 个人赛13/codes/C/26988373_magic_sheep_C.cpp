#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#define LL long long
using namespace std;

set<string> S;

int T,n,m;
vector<int> f;
string a;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		cin>>a;
		if(!S.count(a))
		{
			S.insert(a);
			f.push_back(a.size());
		}
	}
	sort(f.begin(), f.end());
	if(n<f[0])
	{
		printf("0\n");
		return 0;
	}
	n-=f[0];
	int ans=1;
	for(int i=1;i<f.size();i++)
	{
		int res = f[i]+1;
		if(n>=res) n-=res,ans++;
		else break;
	}
	printf("%d\n", ans);
	return 0;
}
