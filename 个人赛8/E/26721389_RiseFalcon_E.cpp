#include <cstdio> 
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=2E5+10;
typedef long long LL;
LL a[MAXN];
string s[MAXN];
char next(char x) {
	x=(x-'a'+1)%26+'a';
	return x;
}
int doing() {
	int n;
	cin>>n;
	LL sum=0;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		sum+=a[i];
	}
	LL preSum=0,mxPreSum=0;
	for(int i=1;i<n;++i) {
		preSum=max(preSum+a[i],a[i]);
		mxPreSum=max(preSum,mxPreSum);
	}
	preSum=0;
	for(int i=2;i<=n;++i) {
		preSum=max(preSum+a[i],a[i]);
		mxPreSum=max(preSum,mxPreSum);
	}
	//cout<<mxPreSum<<" "<<sum<<endl;
	cout<<(sum>mxPreSum ? "YES":"NO")<<endl;
	return 0;
} 
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=1;i<=t;++i) {
		doing();
	}
	return 0;
}