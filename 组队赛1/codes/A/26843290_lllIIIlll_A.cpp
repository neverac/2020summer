#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<pair<int,char> > a,b;

int main()
{
	int n;
	scanf("%d\n",&n);
	char tmp;

	tmp = getchar();
	while (tmp!='\n' && tmp)
	{
		if (tmp<58)
		{
			int hh = tmp-'0';
			while ((tmp=getchar())<58 && tmp!='\n' && tmp)
			{
				hh*=10;
				hh+=tmp-'0';
			}
			a.push_back(make_pair(hh,'a'));
		}
		else
		{
			a.push_back(make_pair(1e9+7,tmp));
			tmp = getchar();
		}
	}

	for (int i=0;i<n;i++)
	{
	b.clear();
	tmp=getchar();
	while (tmp!='\n' && tmp)
	{
		if (tmp<58)
		{
			int hh = tmp-'0';
			while ((tmp=getchar())<58 && tmp!='\n' && tmp)
			{
				hh*=10;
				hh+=tmp-'0';
			}
			b.push_back(make_pair(hh,'a'));
		}
		else
		{
			b.push_back(make_pair(1e9+7,tmp));
			tmp = getchar();
		}
	}
	if (a>b) cout<<'-'<<endl;
	else cout<<'+'<<endl;
	}


	return 0;
}