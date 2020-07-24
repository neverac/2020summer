#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long sum,i,k,s,n,p;
	cin>>k>>n>>s>>p;
	if(n%s!=0)
	sum=n/s+1;
	else
	sum=n/s; 
	sum=sum*k;
	for(i=1;;i++)
	{
		if(i*p>=sum)
		break;
	}
	cout<<i<<endl;
	return 0;
} 
