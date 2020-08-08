#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long a,b,ans=0;

int main()
{
	cin>>a>>b;
	while(b)
	{
		ans+=a/b;
		a = a%b;
		swap(a,b);
	}
	cout<<ans<<endl;
	return 0;
}