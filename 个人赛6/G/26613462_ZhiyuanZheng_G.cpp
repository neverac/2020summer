#include <bits/stdc++.h>
using namespace std;

long long a,b;

long long solve(long long a,long long b){
	if (a==0||b==0) return 0;
	long long tmp=a/b;
	return tmp+solve(b,a-tmp*b);
}
int main(){
	cin>>a>>b;
	if (a<b) swap(a,b);
	long long ans=solve(a,b);
	cout<<ans<<endl;
	return 0;
}

