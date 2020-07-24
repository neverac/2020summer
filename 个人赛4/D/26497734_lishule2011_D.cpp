#include <iostream>
using namespace std;

const int maxn = 1e7+9;

int gcd(int a,int b){
    return b == 0 ? a : gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,n,a,b;
    int cnt = 0;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        cout << "Case #" << ++cnt << ": ";
        cout<<((n / gcd(a,b) % 2 == 1)?"Yuwgna":"Iaka") << endl;
    }
    return 0;
}