#include <bits/stdc++.h>
using namespace std;
int a[110],b[110];

int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	int la=1,lb=1;
	while (1){
		while (a[la]<b[lb]&&la<=n) la++;
		if (la>n) break; 
		while (a[la]>b[lb]&&lb<=n) lb++;
		if (lb>n) break;
	}
	if (la>n) cout<<n-lb+1<<endl;
	else cout<<n-la+1<<endl;
	return 0;
} 

