#include<bits/stdc++.h>
using namespace std;
int n,m,k,pos;
struct node{
	int v,id;
}a[150];
bool cmp(node a,node b){
	if(a.v==b.v)return a.id<b.id;
	return a.v>b.v;
}
bool cmp2(node a,node b){
	return a.id<b.id;
}
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i].v;
		a[i].id = i;
	}
	sort(a+1,a+1+n,cmp);
	cin >> m;
	while(m --){
		cin >> k >> pos;
		sort(a+1,a+k+1,cmp2);
		cout << a[pos].v << endl;
		sort(a+1,a+1+k,cmp);
	} 
	return 0;
}
