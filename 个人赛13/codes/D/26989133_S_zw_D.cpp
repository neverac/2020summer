#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector> 
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ll long long
#define N 610000
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
using namespace std;

struct Edge
{
    int u, v;
    int first,second;
    bool operator<(Edge e){
        if(first == e.first){
            return second < e.second;
        }
        return first < e.first;
    }
}edges[N];
int pre[N];
int du[N];
int n, m;
int find(int x){
    int root = x, tmp;
    while (pre[root] != root)
    {
        root = pre[root];
    }
    while (pre[x] != root)
    {
        tmp = pre[x];
        pre[x] = root;
        x = tmp;
    }
    return root;
}

void gather(int x,int y){
    int xx = find(x),yy = find(y);
    if(xx != yy){
        pre[yy] = xx;
    }
}

int kurscal(){
    for (int i = 1;i<=n;i++){
        pre[i] = i;
    }
    int cnt = 0;
    for (int i = 1; i <= m;i++){
        Edge e = edges[i];
        int xx = find(e.u), yy = find(e.v);
        if(xx != yy){
            cnt++;
            du[e.u]++;
            du[e.v]++;
            gather(e.u, e.v);
            if(cnt == n-1){
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        ans = max(ans, du[i]);
    }
    return ans;
}

int main ()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(b < a)
            swap(a, b);
        edges[i] = {a, b, b, a};
    }
    sort(edges + 1, edges + 1 + m);
    printf("%d\n", kurscal());
    return 0;
}