#include<bits/stdc++.h>
/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime> 
*/
#define ll long long
using namespace std; 
const int N=1e5 + 100;
const double eps=1e-10;
int v[2*N],a[2*N],b[2*N];
set<int> s[6];
int main(){
	int n;
	scanf("%d",&n); 
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		s[a[i]].insert(v[i]);
		s[b[i]].insert(v[i]);
	}
	int x;
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		if(s[x].empty()) printf("-1 ");
		else{
			int y=*(s[x].begin());
			for(int i=1;i<=3;i++) s[i].erase(y);
			printf("%d ",y);
		}
	}
	
	return 0;
}