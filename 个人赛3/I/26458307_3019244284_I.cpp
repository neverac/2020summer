#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll count=0;
    for(ll i=0;i<n;i++)
    {
    	if(s[i]=='+')
    	count++;
    	else
    	count--;
    	if(count<0)
    	count=0;
	}
	cout<<count<<endl;
	return 0;
} 