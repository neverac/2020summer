#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int val[2 * N * N];

int main()
{
    int r, s, p, x, y;
    cin >> r >> s >> p;
    for (int i = 0; i < p; i ++)
    {
        cin >> x >> y;
        val[i] = r - x + 1 + abs(y - s) + (y <= s);
        // cout << val[i] << endl;
    }
    sort(val, val + p);
    int ans = 0, time = 0;
    for (int i = 0; i < p; i ++)
    {
        if (time < val[i])
            time = val[i];
        else  
            time ++;
        // cout << i << " " << val[i] << " " <<  time << endl;
    }
    cout << time << endl;
}