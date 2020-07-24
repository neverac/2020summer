#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
int t, s = 1;
    cin >> t;
    while(t --)
    {
        int n, a, b;
        cin>> n >> a >> b;
        if(n / gcd(a,b) % 2 == 0)
            cout << "Case #" << s ++ << ": Iaka" << endl;
        else
            cout << "Case #" << s ++ << ": Yuwgna" << endl;
    }
    //system("pause");
    return 0;
}