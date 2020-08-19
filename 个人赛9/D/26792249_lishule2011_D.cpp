#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+100;
struct node{
    int x,y,z,id;
}a[maxn];
bool cmp(node x,node y){
    if (x.x == y.x && x.y == y.y) return x.z<y.z;
    else if (x.x == y.x) return x.y<y.y;
    else return x.x<y.x;
}
int vis[maxn];
vector <node> v,v2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >>a[i].x>>a[i].y>>a[i].z;
        a[i].id = i;
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<n;i++)
        if (!vis[i])
            if (a[i].x == a[i+1].x && a[i].y == a[i+1].y) {
                vis[i] = vis[i+1] =1;
                cout << a[i].id <<' '<<a[i+1].id<<endl;
            }
    for (int i = 1;i<=n;i++)
        if (!vis[i])
            v.push_back(a[i]);
    if (!v.size()) return 0;
    memset(vis,0,sizeof(vis));
    for (int i=0;i<v.size()-1;i++)
        if (!vis[i])
            if (v[i].x == v[i+1].x ) {
                vis[i] = vis[i+1] =1;
                cout << v[i].id <<' '<<v[i+1].id<<endl;
            }
    for (int i = 0;i<v.size();i++)
        if (!vis[i])
            v2.push_back(v[i]);
    if(v2.size())
        for (int i=0;i<v2.size()-1;i+=2)
            cout <<v2[i].id <<' '<<v2[i+1].id<<endl;

    return 0;
}