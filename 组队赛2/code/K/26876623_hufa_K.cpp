#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

priority_queue <long long,vector <long long>,greater<long long> > yxdl;

int main()
{
	long long sum,p,tmp1,tmp2,tmp3;
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		while(!yxdl.empty())
			yxdl.pop();
		sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%lld",&p);
			yxdl.push(p);
		}
		while(!yxdl.empty())
		{
			tmp1=yxdl.top();
			yxdl.pop();
			tmp2=yxdl.top();
			yxdl.pop();
			tmp3=tmp1+tmp2;
			sum+=tmp3;
			if(!yxdl.empty())
				yxdl.push(tmp3);
		}
		printf("%lld\n",sum);
	}
return 0;
}