#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

// 筛法
bool vis[N];
int prime[N], cnt;
void get_mu()
{
    for (int i = 2; i < N; ++i)
    {
        if (!vis[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && prime[j] * i < N; ++j)
        {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}


int cc[5];

int main()
{
    ios::sync_with_stdio(false);
    // get_mu();
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> x;
        cc[x] ++;
    }
    
    if (cc[2])
    {
        cout << 2 << " ";
        cc[2] --;
    }

    if (cc[1])
    {
        cout << 1 << " ";
        cc[1] --;
    }

    for (int i = 0; i < cc[2]; i ++)
        cout << 2 << " ";
    
    for (int i = 0; i < cc[1]; i ++)
        cout << 1 << " ";
    cout << endl;

    // int pre = 0;
    // for (int i = 0; i < cnt; i ++)
    // {
    //     int sub = prime[i] - pre;
    //     // cout << sub << endl;
    //     int t1 = min(cc[2], sub / 2);
    //     // cout << t1 << endl;
    //     for (int j = 0; j < t1; j ++)
    //         cout << 2 << " ";
    //     cc[2] -= t1;
    //     sub -= t1 * 2;

    //     int t2 = min(cc[1], sub);
    //     for (int j = 0; j < t2; j ++)
    //         cout << 1 << " ";
    //     cc[1] -= t2;

    //     if (cc[1] + cc[2] == 0)
    //         break;
    //     pre = prime[i] - sub;
    // }
    
}