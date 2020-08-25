#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
struct node{
	int len;
	string s;
}a[1100];

bool cmp(node x,node y){
	if (x.len==y.len) return x.s<y.s;
	return x.len<y.len;
}
map <string,bool> mp;
int main(){
	IO;
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=k;i++){
		cin>>a[i].s;
		a[i].len=a[i].s.size();
	}
	sort(a+1,a+1+k,cmp);
	int ans=0;
	for (int i=1;i<=k;i++){
		if (!mp.count(a[i].s)){
			if (n==a[i].len){
				mp[a[i].s]=true;
				n-=a[i].len;
				ans++;
			}else{
				if (n>=a[i].len+1){
					mp[a[i].s]=true;
					n-=a[i].len+1;
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

