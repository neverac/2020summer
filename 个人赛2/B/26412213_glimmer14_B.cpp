#include <iostream>
#include <cstring>
using namespace std;

const int N = 70000;
const int M = 16;
bool vis[N];
int ans[20];

int a, b, c, x;
inline bool cal()
{
    x = (a * x + b) % c;
    if (vis[x]) return false;
    vis[x] = true;
    for (int i = 0; i < M; i ++)
        if (ans[i] != !!(x & (1 << i)))
            ans[i] = -1;
    return true;
}

int main()
{
    while (cin >> a, a)
    {
        cin >> b >> c >> x;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < M; i ++)
            ans[i] = !!(x & (1 << i));
        
        while (cal());

        for (int i = M - 1; i >= 0; i --)
            cout << (char)(ans[i] == -1 ? '?' : ans[i] + '0');
        cout << endl;


    }
    
}