#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 2e5+100;

long long res,bs=26;
char ans[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin>>res;
	int cnt=0;
	while(res)
	{
		long long ip = res%bs;
		res/=bs;
		if(ip==0) ip=26,res--;
		char op = 'a'+ip-1;
		ans[++cnt]=op;
		//cout<<ip<<endl;
	}
	for(int i=cnt;i>=1;i--) cout<<ans[i];
	cout<<endl;
	return 0;
}