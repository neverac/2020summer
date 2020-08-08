#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a, b;
LL solve(LL x, LL y){
    if(y == 1) return x;
    return solve(y ,x % y) + x / y;
}
int main(){
    cin>>a>>b;
    cout<<solve(a, b)<<endl;
    return 0;
}