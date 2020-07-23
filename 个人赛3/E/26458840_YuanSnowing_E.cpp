#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[100050],b[100050],f[2][100050];
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n; ++ i){
    	scanf("%lld",a+i);
    }
    for(int i = 0;i < n; ++ i){
    	scanf("%lld",b+i);
    }
    f[0][0] = a[0];
    f[1][0] = b[0];
    f[0][1] = max(b[0]+a[1], a[0]);
    f[1][1] = max(a[0]+b[1], b[0]);
    for(int i = 1;i < n; ++ i){
    	f[0][i] = max(f[1][i-1]+a[i], f[0][i-1]);
    	f[1][i] = max(f[0][i-1]+b[i], f[1][i-1]);
    }
    printf("%lld\n",max(f[1][n-1],f[0][n-1]));
}