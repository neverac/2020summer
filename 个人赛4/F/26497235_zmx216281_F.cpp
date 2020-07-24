#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int k,n,s,p,tem,ans;
    cin >> k >> n >> s >> p;
    if(n%s==0){
        tem = n*k/s;
    }
    else{
        tem = (n/s+1)*k;
    }
    if(tem%p==0){
        ans = tem/p;
    }
    else{
        ans = (tem/p+1);
    }
    cout << ans << endl;
    return 0;
}
