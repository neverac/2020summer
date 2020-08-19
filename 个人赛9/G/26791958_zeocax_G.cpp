#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define ll long long
using namespace std;
const int int_inf = 0x3f3f3f3f;
inline int readint()
{
    int ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
inline ll readll()
{
    ll ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
int p[200100];
int a[200100], b[200100];
map<int, int>f;
set<int>s[3];
int main(){
    int n = readint();
    for(int i = 1; i <= n; i++){
        p[i] = readint();
        f[p[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        a[i] = readint();
        s[a[i] - 1].insert(p[i]);
    }
    for(int i = 1; i <= n; i++){
        b[i] = readint();
        s[b[i] - 1].insert(p[i]);
    }
    int m = readint();
    for(int i = 1; i <= m; i++){
        int c = readint();
        if(s[c - 1].empty()){
            printf("-1 ");
        }
        else{
            int ans = *(s[c - 1].begin());
            printf("%d ", ans);
            int id = f[ans];
            s[a[id] - 1].erase(ans);
            s[b[id] - 1].erase(ans);
        }
    }
    return 0;
}