#include <iostream>
using namespace std;
int main(){
    long long  k, n, s, p;
    cin >> k >> n >> s >> p;
    long long sheet ;
    if(!(n%s)){
        sheet = n/s;
    }
    else{
        sheet = n/s + 1;
    }
    sheet*=k;
    //cout << sheet << endl ;
    if(!(sheet%p)){
        p=sheet/p;
    }
    else{
        p=sheet/p+1;
    }
    cout << p << endl ;
    return 0;
}