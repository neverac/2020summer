#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
using namespace std;
const int int_inf = 0x3f3f3f3f;
inline int readint()
{
    int ret = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret * f;
}
inline ll readll()
{
    ll ret = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret * f;
}
int f[1100];
map<string, bool>vis;
int cnt = 0, len[1100];
int main(){
    int n = readint(), m = readint();
    while(m--){
        string str;
        cin >> str;
        if(vis[str])continue;
        vis[str] = true;
        ++cnt;
        len[cnt] = str.length();
    }
    //
    for(int i = 1; i <= cnt; i++)
    for(int j = n + 1; j >= len[i] + 1; j--){ // a _ b _ c
        f[j] = max(f[j], f[j - len[i] - 1] + 1);
    }
    printf("%d", f[n + 1]);
    return 0;
}