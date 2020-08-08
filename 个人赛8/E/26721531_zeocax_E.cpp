#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
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
int a[100100];
priority_queue<ll, vector<ll>, greater<ll>>q;
int main(){
    int T = readint();
    while(T--){
        int n = readint();
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        ll ans = 0;
        ll pre = 0;
        while(!q.empty())q.pop();
        q.push(0);
        for(int i = 1; i <= n - 1; i++){
            pre += a[i];
            ll mn = q.top();
            ans = max(ans, pre - mn);
            q.push(pre);
        }
        pre = 0;
        while(!q.empty())q.pop();
        q.push(0);
        for(int i = 2; i <= n; i++){
            pre += a[i];
            ll mn = q.top();
            ans = max(ans, pre - mn);
            q.push(pre);
        }
        if(sum > ans){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}