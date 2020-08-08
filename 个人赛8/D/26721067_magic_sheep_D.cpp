#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T,n,a[1000];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		string str(200,'a');
    	cout<<str<<endl;
	    for (int i=1;i<=n;i++) {
	       int op;
	       cin>>op;
	       str[op]=str[op]=='a'?'b':'a';
	       cout<<str<<endl;
	    }
	}
	return 0;
}