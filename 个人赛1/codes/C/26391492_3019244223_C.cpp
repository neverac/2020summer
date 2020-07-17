#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<cstdio>
#include<set>
using namespace std;
int  main()
{
    int num;
    cin>>num;
    for(int i=0;i<num;++i)
    {
    	int n;
    	cin>>n;
    	vector<int> Q;
		Q.clear();
		vector<int> ans;
		set<int> p;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			Q.push_back(x);
			p.insert(j+1);
		}
		int max = 0;
		bool judge=1;
		for(int j=0;j<n;j++)
		{
			if(Q[j]>max)
			{
				if(p.count(Q[j]))
				{
					p.erase(Q[j]);
					ans.push_back(Q[j]);
				}
				else
				{
					judge=0;
					break;
				}
				max = Q[j];
			}
			else
			{
				if(*p.begin()>max)
				{
					judge=0;
					break;
				}
				else
				{
					ans.push_back(*p.begin());
					p.erase(p.begin());
				}
			}
		}
		if(judge==0)
		{
			cout<<-1<<endl;
			continue;
		}
		for(int j=0;j<ans.size();j++)
			cout<<ans[j]<<" ";
		cout<<endl;
    }
    return 0;
}

