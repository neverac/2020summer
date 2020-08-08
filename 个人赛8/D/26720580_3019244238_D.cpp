#include <iostream>
#include <string>
using namespace std;

string str[1050];

int main()
{
	int t,n,a[150];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		str[0]="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
		for(int i=1;i<=n;++i)
		{
			str[i]=str[i-1];
			str[i][a[i]]=(str[i][a[i]]-'a'-1+26)%26+'a';
		}
		for(int i=0;i<=n;++i)
			cout<<str[i]<<endl;
	}
return 0;
}