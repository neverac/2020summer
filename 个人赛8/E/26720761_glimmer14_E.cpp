#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int val[N];

int main()
{
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i ++)
            cin >> val[i];
        
        bool f = true;
        long long sum = 0;
        for (int i = 0; i < n; i ++)
        {
            sum += val[i];
            if (sum <= 0)
            {
                f = false;
                break;
            }
        }

        if (f)
        {
            sum = 0;
            for (int i = n - 1; i >= 0; i --)
            {
                sum += val[i];
                if (sum <= 0)
                {
                    f = false;
                    break;
                }   
            }
        }

        cout << (f ? "YES" : "NO") << endl;
    }
    
}