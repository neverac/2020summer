/*
 *powered by caibiCH2
 *create at 2020/8/13 17:02
 */


#include <bits/stdc++.h>

#define elif else if
//#define max(x,y) ((x)>(y)?(x):(y))
//#define min(x,y) ((x)<(y)?(x):(y))
#define INF 0x3f3f3f3f
#define pb push_back
#define pf push_front
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct pnt {
    int x, y;
} p[20100];
struct msp{
    int c;
    int next[8];
}pw[20100];
int np[20100],used[20100];

bool search(int st,int ed,int c1,int c2){
    queue<int>q;q.push(st);
    vector<int>vused(1,st);
    used[st]=1;
    while(q.size()){
        int now=q.front();q.pop();
        for(int i=0;i<8;++i){
            int v=pw[now].next[i];
            if(v&&!used[v]&&(pw[v].c==c1||pw[v].c==c2)){
                q.push(v);
                vused.pb(v);
                used[v]=1;
            }
        }
    }
    int flag=used[ed];
    for(int i:vused)used[i]=0;
    if(flag)return 0;
    else{
        for(int i:vused){
            pw[i].c^=c1^c2;
        }
        return 1;
    }
}

signed main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y;
        np[i] = i;
    }
    map<pair<int, int>, int> ms;
    ms[{1, 0}] = 0, ms[{1, 1}] = 1, ms[{0, 1}] = 2, ms[{-1, 1}] = 3,
    ms[{-1, 0}] = 4, ms[{-1, -1}] = 5, ms[{0, -1}] = 6, ms[{1, -1}] = 7;
    for (int i = 1; i <= m; ++i) {
        int s, t;
        cin >> s >> t;
        pair<int, int> pst = {p[t].x - p[s].x, p[t].y - p[s].y};
        int e = max(abs(pst.first), abs(pst.second));
        pst.first /= e, pst.second /= e;
        pair<int, int> pts = {-pst.first, -pst.second};
        pw[s].next[ms[pst]] = t, pw[t].next[ms[pts]] = s;
    }
    sort(np + 1, np + n + 1, [&](int x, int y) {
        return p[x].y < p[y].y || p[x].y == p[y].y && p[x].x < p[y].x;
    });
    for (int i = 1; i <= n; ++i) {
        int now = np[i];
        int usable[5]{};
        for (int j = 4; j < 8; ++j)if (pw[now].next[j]) usable[pw[pw[now].next[j]].c] = 1;
        int flag = 0;
        for (int j = 1; j <= 4; ++j) {
            if (!usable[j]) {
                pw[now].c = j;
                flag = 1;
                break;
            }
        }
        if (flag)continue;
        int lftc=pw[pw[now].next[4]].c;
        if(search(pw[now].next[4],pw[now].next[6],pw[pw[now].next[4]].c,pw[pw[now].next[6]].c)){
            pw[now].c=lftc;
        }else {
            lftc=pw[pw[now].next[5]].c;
            search(pw[now].next[5], pw[now].next[7], pw[pw[now].next[5]].c, pw[pw[now].next[7]].c);
            pw[now].c=lftc;
        }
    }
    for(int i=1;i<=n;++i){
        cout<<pw[i].c<<'\n';
    }
// cout<<'+'<<'\n';
    return 0;
}