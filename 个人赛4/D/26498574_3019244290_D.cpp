#include <iostream>
 
using namespace std;
 
int gcd( int a, int b )
{
    if ( b==0 ) {
        return a;
    }
    return gcd(b,a%b);
}
 
int main()
{
    int i=1,n,t,a,b;
    cin >> t;
    while ( t-- ) {
        cin >> n >> a >> b;
        int ans = n/gcd(a,b);
        cout << "Case #" << i++ << ": ";
        if ( ans%2==0 ) {
            cout << "Iaka" << endl;
        }
        else {
            cout << "Yuwgna" << endl;
        }
    }
 
    return 0;
}