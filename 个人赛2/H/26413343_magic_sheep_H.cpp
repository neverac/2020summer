#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

LL cnt1,cnt2,x,y;

bool judge(LL X)
{
	if(X-X/(x*y)<cnt1+cnt2) return false;
	if(X-X/x<cnt1) return false;
	if(X-X/y<cnt2) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>cnt1>>cnt2>>x>>y;
	LL l =1,r=1e15+100,ans;
	while(l<=r)
	{
		LL mid = (l+r)>>1;
		if(judge(mid)) {
			r = mid-1;
			ans = mid;
		}
		else l =mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
