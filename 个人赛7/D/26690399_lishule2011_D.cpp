
#include <iostream>
using namespace std;
long long pd(long long x){
    while(x%2==0) x/=2;
    long long ret=1;
    for(int i=3;i<=7;i+=2){
        long long temp=1;
        long long sum=1;
        int num=0;
        while(x%i==0) num++,x/=i,temp*=i,sum+=temp;
        ret=ret*sum;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        long long x;
        cin >> x;
        cout << pd(x) << endl;
    }
    return 0;
}
