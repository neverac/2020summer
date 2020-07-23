#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cnt1,cnt2,n,x;
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n; ++ i){
    	cin >> x;
    	if(x == 1) cnt1 ++;
    	else cnt2 ++;
    }
    if(cnt2 > 0){
    	cout << 2;
    	-- cnt2;
    	-- n;
    }
    if(n == 0) cout << endl;else cout << " ";
    if(cnt1 > 0){
    	cout << 1;
    	-- cnt1;
    	-- n;
    }
    if(n == 0) cout << endl;else cout << " ";
    while(cnt2 --){
    	cout << 2;
    	-- n;
    	if(n == 0) cout << endl;else cout << " ";
    }
    while(cnt1 --){
    	cout << 1;
    	-- n;
    	if(n == 0) cout << endl;else cout << " ";
    }
}