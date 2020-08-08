#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        int t=k/(n-1);
        int num=k-t*(n-1);
        if(k==t*(n-1))num--;
        num+=t*n;
        cout << num << endl ;
    }
    return 0;
}
