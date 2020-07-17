#include <bits/stdc++.h>
using namespace std;
int a[2000];
int n,k;
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int s=0;
	for (int i=1;i<=k;i++) s+=a[i];
	cout<<s<<endl;
	return 0;
}

