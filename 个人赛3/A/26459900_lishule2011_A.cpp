#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+100;

struct edge{
    int from ,to;
}edges[maxn];

vector <int> G[maxn];
int n,m,vis[maxn],c[maxn];

void addedge(int x,int y,int i){
    edges[i].from = x;
    edges[i].to = y;
    G[x].push_back(y);
    vis[edges[i].to] ++;
}

int dfs(){
    queue <int> Q;
    for (int i = 1;i<=n;i++) if (!vis[i]) Q.push(i);
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (int i=0;i<G[u].size();i++){
            int p = G[u][i];
            vis[p]--;
            if(!vis[p]) Q.push(p);
        }
    }
    int now = 0;
    for (int i=1;i<=n;i++) now |= vis[i];
    return now;
}


void work(){
    if (!dfs()){
        cout << 1 << endl;
        for (int i=1;i<=m;i++)
            cout << 1 <<' ';
    }
    else{
        cout << 2 << endl;
        for (int i = 1;i<=m;i++)
            if (edges[i].from<edges[i].to) cout << 1 <<' ';
            else cout << 2 << ' ';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        addedge(x,y,i);
    }

    work();

    return 0;
}