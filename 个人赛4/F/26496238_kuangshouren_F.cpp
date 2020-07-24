#include<iostream>
#include<cstring>
using namespace std;
long long k,n,s,p;
int main()
{
	cin>>k>>n>>s>>p;
	long long x=(n-1)/s+1;
	cout<<(k*x-1)/p+1;
	return 0;
}