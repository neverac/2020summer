#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5+100;

int n,k;
int a[maxn];

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
	int sum =0 ;
	for(int i=1;i<=k;i++) sum+=a[i];
		cout<<sum<<endl;
	return 0;
}