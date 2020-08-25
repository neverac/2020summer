#include<bits/stdc++.h>
using namespace std;

int main(){
    double x, y, z, ans = 1000000000.0;
    int n; cin>>n;
    for(int i = 1; i <= n; i++){
        scanf("%lf%lf%lf", &x, &y, &z);
        double dis = x * x + y * y + z * z;
        if(dis < ans) ans = dis;
    }
    printf("%.3f\n", sqrt(ans));
    return 0;
}