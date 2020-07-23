#include<bits/stdc++.h>
using namespace std;
char s[200];
#define LL long long
LL mx[100010][2],f[100010][2],h[100010][2];
int main(){
	int n; cin>>n;
	for (int i=1; i<=n; i++) scanf("%d",&h[i][0]);
	for (int i=1; i<=n; i++) scanf("%d",&h[i][1]);
	for (int i=1; i<=n; i++){
		f[i][0] = max(mx[i-1][1]+h[i][0],f[i-1][1]);
		f[i][1] = max(mx[i-1][0]+h[i][1],f[i-1][0]);
		mx[i][0] = max(mx[i-1][0],f[i][0]);
		mx[i][1] = max(mx[i-1][1],f[i][1]);
	}
	printf("%lld\n",max(f[n][0],f[n][1]));
	return 0;
}