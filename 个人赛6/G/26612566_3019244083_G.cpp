#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	ll x=a%b,res=0;
	while(x>0)
	{ 
		res += a/b;
        a=b;
        b=x;
        x=a%b;
	}
	res += a/b;
	return res;
}
int main()
{
	ll a,b;
	cin>>a>>b;
	if(a==b) printf("1");
	else{
		ll k = gcd(a,b);
		cout<<k<<endl;
	}
	return 0;
}