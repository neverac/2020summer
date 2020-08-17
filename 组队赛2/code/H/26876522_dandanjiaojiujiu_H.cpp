#include <bitset>
#include <iostream>
using namespace std;
typedef long long LL;
int main()
{
    int T, n, m;
    cin >> T;
    while (T--)
    {
        LL n;
        cin>>n;
        cout<<((n*(n+1))^(n+1))<<endl;
    }
    return 0;
}