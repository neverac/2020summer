#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <bitset>
#define ll long long
using namespace std;
const int int_inf = 0x3f3f3f3f;
const ll ll_inf = 1e18;
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
bitset<500>machine[15];
int main(){
    int T = readint();
    while(T--){
        int n = readint(), m = readint();
        for(int i = 0; i < m; i++){
            string str; cin >> str;
            bitset<500>b(str);
            machine[i] = b;
        }
        int ans = int_inf;
        for(int i = 1; i < (1 << m) - 1; i++){
            bitset<500>sum(0x0);
            int cnt = 0;
            for(int j = 0; j < m; j++)
            if(i & (1 << j)){
                sum |= machine[j];
                ++cnt;
            }
            if(sum.count() == n){
                ans = min(ans, cnt);
            }
        }
        if(ans != int_inf)printf("%d\n", ans);
        else printf("-1\n");
    }
    return 0;
}