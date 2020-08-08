#include <bits/stdc++.h>
using namespace std;
int n;
long long a[400],ans,now,mon,maxn= 100000;
int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n; ++ i){
    	cin >> a[i];
    }
    a[0] = 501LL;
    a[n+1] = -100LL;
    mon = 100LL;
    for(int i = 1;i <= n; ++ i){
    	if(a[i]<=a[i+1] && a[i-1]>a[i]){ //buy
    		long long tmp = mon/a[i];
    		if(tmp > maxn) tmp = maxn;
    		mon -= a[i]*tmp;
    		now += tmp;
    	}else if(a[i]>a[i+1] && a[i-1]<=a[i]){ //sell
    		mon += a[i]*now;
    		now = 0;
    	}
    }
    cout << mon << endl;
    return 0;
} 