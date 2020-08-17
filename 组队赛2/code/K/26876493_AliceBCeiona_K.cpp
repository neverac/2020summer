#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--){
		priority_queue <int,vector<int>, greater<int> > q;
		int n,x;
		cin>>n;
		for(int i = 1; i <= n; ++i) {cin>>x;q.push(x);}
		int ans = 0;
	 	while(q.size() >= 2){
	 		int x1=q.top();
	 		q.pop();
	 		int x2=q.top();
	 		q.pop();
	 		ans += x1+x2;
	 		q.push(x1+x2);
	 	}
	 	cout<<ans<<endl;
	}
	
	return 0;
} 