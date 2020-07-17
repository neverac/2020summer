#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
const long long int maxn=5e5+500,inf=1e9;
long long int x[maxn],y[maxn],z[maxn],ans[maxn],cnt[maxn],last[maxn];
pair<long long int,long long int> vec[maxn];
pair<long long int,pair<long long int,long long int>> gh[maxn];
void cleann(long long int n){
	n+=2;
	fill(vec,vec+n,make_pair(0,0));
	fill(cnt,cnt+n,0);
	fill(gh,gh+n,make_pair(0,make_pair(0,0)));
	fill(ans,ans+n,0);
	fill(last,last+n,-1);
}
void solve(long long int n,long long int k,long long int m){
	for(long long int i=0;i<m;i++){
		if(vec[z[i]]!=make_pair(0ll,0ll)){
			cout<<"No\n";
			return;
		}
		gh[i]=make_pair(z[i],make_pair(x[i],y[i]));
		vec[z[i]]=make_pair(x[i],y[i]);
	}
	set<long long int> llset;
	for(long long int i=1;i<=n;i++){
		if(vec[i]==make_pair(0ll,0ll)){
	        llset.insert(i);
		}
	}
	sort(gh,gh+m);
	for(long long int i=0;i<m;i++){
		long long int x=gh[i].second.first;
		long long int y=gh[i].second.second;
		long long int z=gh[i].first;
		long long int s;
		if(last[x]==-1){
			s=0;
		}else{
			s=gh[last[x]].first+1;
		}
		last[x]=i;
		while(cnt[x]+1<y){
			auto it=llset.lower_bound(s);
			if(it==llset.end()||(*it)>=z){
				cout<<"No\n";
				return ;
			}
			ans[*it]=x;
			llset.erase(it);
			cnt[x]++;
		}
		ans[z]=x;
		cnt[x]++;
		if(cnt[x]!=y){
			cout<<"No\n";
			return;
		}
	}
	pair<long long int,long long int> o=make_pair(inf,inf);
	for(long long int i=1;i<=k;i++){
		o=min(o,make_pair(last[i],i));
	}
	long long int s=-1;
	if(o.first!=-1)s=gh[o.first].first;
	for(long long int i=1;i<=n;i++){
		if(ans[i]==0 && i<s){
			cout<<"No\n";
			return ;
		}
		if(ans[i]==0){
			ans[i]=o.second;
		}
	}
	cout<<"Yes\n";
	for(long long int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}
int main(){
	long long int t;
    cin>>t;
	for(long long int iii=0;iii<t;iii++){
		long long int n,k,m;
        cin>>n>>k>>m;
		for(long long int i=0;i<m;i++){
            cin>>x[i]>>y[i]>>z[i];
		}
		long long int mxx=max(n,max(k,m));
		cleann(mxx);
		solve(n,k,m);
	}
}