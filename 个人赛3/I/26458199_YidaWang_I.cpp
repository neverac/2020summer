#include<bits/stdc++.h>
using namespace std;
char s[200];
int main(){
	int n; cin>>n;
	scanf("%s",s+1);
	int mx = 0,cnt=0;
	for (int i=1; i<=n; i++){
		if (s[i] == '-') cnt--;
		else cnt++;
		if (cnt < 0) mx = max(mx,-cnt);
	}
	for (int i=1; i<=n; i++){
		if (s[i] == '-') mx--;
		else mx++;
	}
	printf("%d\n",mx);
	return 0;
}