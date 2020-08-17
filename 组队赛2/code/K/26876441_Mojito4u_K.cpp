#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
int const maxn=4010;
int a[maxn];
 priority_queue<int,vector<int> , greater<int>  > q;
int n;
int main(){
	int t;

	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		while(!q.empty())q.pop();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q.push(a[i]);
	}
	int ans=0,a,b;
	while(q.size()!=1){
		a=q.top();q.pop();
		b=q.top();q.pop();
		ans+=(a+b);
		q.push(a+b);
	}
	printf("%d\n",ans);
	}
	
	return 0;
}