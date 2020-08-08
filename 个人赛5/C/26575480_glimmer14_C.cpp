#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500;
ll M = 100000;


int val[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> val[i];
    
    ll stock = 0;
    ll sum = 100;
    val[0] = val[1];
    val[n + 1] = 0;
    for (int i = 0; i <= n; i ++)
    {
        if (val[i + 1] < val[i])
        {
            sum += val[i] * stock;
            stock = 0;
        }
        else if (!stock)
        {
            stock = min(sum / val[i], M);
            sum -= stock * val[i];
        }
        
    }
    cout << sum << endl;
}