#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 3006
#define ll long long
#define dd double
#define esp 1e-10
using namespace std;

int n,k;
int a[1000006];

int main(){
	ll ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=k;++i)
		ans+=a[i];
	cout<<ans;
}