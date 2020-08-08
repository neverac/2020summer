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
char S[100100];
vector<int>link[26];
int main(){
    int k = readint();
    scanf("%s", S + 1);
    int len = strlen(S + 1);
    for(int i = 1; i <= len; i++){
        link[S[i] - 'a'].push_back(i);
    }
    ll ans = 0;
    for(int i = 0; i < 26; i++){
        int siz = link[i].size();
        for(int j = 0; j < siz; j++){
            int st, ed;
            if(j == 0) st = 1;
            else st = link[i][j - 1] + 1;
            if(j + k >= siz){ // j + k - 1 + 1
                ed = len;
            }
            else{
                ed = link[i][j + k] - 1;
            }
            ans += 1ll * (link[i][j] - st + 1) * (ed - link[i][j] + 1);
        }
    }
    printf("%lld", ans);
    return 0;
}