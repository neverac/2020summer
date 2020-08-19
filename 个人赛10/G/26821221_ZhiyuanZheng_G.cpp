#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int num,pos;
}a[110]; 
bool cmp(node x,node y){
	if (x.num==y.num) return x.pos<y.pos;
	return x.num>y.num;
}
bool cmps(node x,node y){
	return x.pos<y.pos;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]={x,i};
	}
	sort(a+1,a+1+n,cmp);
	int q;
	cin>>q;
	vector <node> v;
	while (q--){
		int k,ps;
		cin>>k>>ps;
		v.clear();
		for (int i=1;i<=k;i++){
			v.push_back(a[i]);
		}
		sort(v.begin(),v.end(),cmps);
		cout<<v[ps-1].num<<endl;
	}
	return 0;
}

