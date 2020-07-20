#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int x = 1, sgn = 1;
    cout << x << " ";
    for (int i = k; i >= 1; i --)
    {
        x += sgn * i;
        sgn *= -1;
        cout << x << " ";
    }
    for (int i = k + 2; i <= n; i ++)
        cout << i << " ";
    cout << endl;
}
