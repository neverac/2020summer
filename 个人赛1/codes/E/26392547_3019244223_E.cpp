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
	long long n;
	cin>>n;
	int a;
	int x[1000];
	int num=0;
	while(n)
	{
		a=(n-1)%26;
		x[num++]=a;
		n--;
		n=n/26;
	}
	for(int i=num-1;i>=0;--i)
		cout<<static_cast<char>(x[i]+'a');
    return 0;
}

