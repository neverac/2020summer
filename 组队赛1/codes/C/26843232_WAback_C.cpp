#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2*510*510;
int r,s,p;
int X[MAXN],Y[MAXN],ans[MAXN]; 
int main(){
	scanf("%d%d%d",&r,&s,&p);
	for (int i=1; i<=p; i++){
		scanf("%d%d",&X[i],&Y[i]);
		if (Y[i] <= s) ans[i] = r-X[i]+1 + s-Y[i]+1;
		else ans[i] = r-X[i]+1 + Y[i]-s;
	} 
	sort(ans+1,ans+p+1);
	int mx = ans[1];
	for (int i=2; i<=p; i++){
		if (ans[i] <= mx) mx++; 
		else mx = max(mx,ans[i]); 
	}
	printf("%d\n",mx);
	return 0;
} 