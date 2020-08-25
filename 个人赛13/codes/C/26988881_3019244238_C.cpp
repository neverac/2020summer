#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map <string,int> mark;

int main()
{
	string str;
	int n,m,ans=0,tmp[1050],cnt=0,sum=-1,now=0;
	cin>>n>>m;
	while(m--)
	{
		cin>>str;
		if(!mark[str])
			mark[str]=1,tmp[cnt++]=str.length();
	}
	sort(tmp,tmp+cnt);
	while(now<cnt && sum<=n)
	{
		sum+=tmp[now++]+1;
		++ans;
	}
	if(sum>n)
		--ans;
	cout<<ans<<endl;
return 0;
}