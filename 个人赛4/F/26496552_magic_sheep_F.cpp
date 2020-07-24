#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

LL k,n,s,p,ans;

int main()
{
	cin>>k>>n>>s>>p;
	if(n%s) ans = n/s+1;
	else ans = n/s;
	ans*=k;
	int cnt =0;
	while(++cnt)
	{
		if(cnt*p>=ans) break;
	}
	cout<<cnt<<endl;

	return 0;
}