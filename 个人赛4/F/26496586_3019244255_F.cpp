#include <iostream>
using namespace std;

int main()
{
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    int sum = 0;
    int sum1 = 0;
    if(n % s == 0)
    sum1 = n / s;
    else 
    sum1 = n / s + 1;
    if(sum1 * k % p == 0)
    sum = sum1 * k / p;
    else 
    sum = sum1 * k / p + 1;
    cout << sum;

    return 0;
}