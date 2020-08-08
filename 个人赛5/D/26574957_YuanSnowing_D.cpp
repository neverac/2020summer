#include <bits/stdc++.h>
using namespace std;
int T;
long long n,k,ans;
int main(){
    scanf("%d",&T);
    while(T --){
    	cin >> n >> k;
    	ans = k/(n-1)*n+k%(n-1);
    	if(k%(n-1)==0) ans --;
    	cout << ans << endl;
    }
    return 0;
} 