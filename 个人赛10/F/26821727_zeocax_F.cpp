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
ll len, ans = 0;
ll a[100100];
struct Node{
    Node *l, *r;
}root;
int main(){
    int n = readint();
    for(int i = 1; i <= n; i++){
        a[i] = readll();
        ans = max(ans, a[i]);
    }
    sort(a + 1, a + n + 1);
    len = unique(a + 1, a + n + 1) - (a + 1);
    root.l = root.r = NULL;
    for(int i = 1; i <= len; i++){
        Node *cur = &root;
        for(int j = 29; j >= 0; j--){
            if(a[i] & (1 << j)){
                if(cur -> r != NULL){
                    cur = cur -> r;
                }
                else{
                    Node *nxt = new Node();
                    nxt -> l = nxt -> r = NULL;
                    cur -> r = nxt;
                    cur = nxt;
                }
            }
            else{
                if(cur -> l != NULL){
                    cur = cur -> l;
                }
                else{
                    Node *nxt = new Node();
                    nxt -> l = nxt -> r = NULL;
                    cur -> l = nxt;
                    cur = nxt;
                }
            }
        }
    }
    for(int i = 1; i <= len; i++){
        ll tans = 0;
        Node *cur = &root;
        for(int j = 29; j >= 0; j--){
            if(a[i] & (1 << j)){
                if(cur -> l != NULL){
                    tans = tans | (1 << j);
                }
                cur = cur -> r;
            }
            else{
                if(cur -> r != NULL){
                    tans = tans | (1 << j);
                }
                cur = cur -> l;
            }
        }
        ans = min(ans, tans);
    }
    printf("%lld", ans);
    return 0;
}