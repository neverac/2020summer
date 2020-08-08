#include <bits/stdc++.h>
using namespace std;
int a[150],b[150],n;
int main(){
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=n;++i) cin >> b[i];
	int ans=n*2,p=1;
	for(int i=1;i<=n;++i){
		while(p<=n){
			if(a[i]<b[p]){
				-- ans;
				break;
			}
			else {
				-- ans;
				++ p; 
			}
		}
	}
	cout << ans << endl;
	return 0;
}
