/*
（为防止过于冗长，仅展示代码核心部分，省略了繁杂的模板）
*/

/*
 *powered by caibiCH2
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

typedef double T;
const double Pi = 3.14159265358979323846;
double eps = 1e-4;
struct vec{T x, y;}
typedef vec node;
struct line{vec dir;node pnt;};
struct seg{node pnt1, pnt2;};
struct poly{vector<node> pnt;vector<seg> edge;};

inline double rand01() { return double(rand()) / (ll(RAND_MAX) + 1); }
double dta_eps=1e-12;
double halfgo(auto f){
    double x=rand01();
    double now=f(x);
    for(double i=1;i>=dta_eps;i/=2){
        double l=max(0.,x-i),r=min(1.,x+i);
        double fl=f(l),fr=f(r);
        if(fl<now)x=l,now=fl;
        if(fr<now)x=r,now=fr;
    }
    return now;
}

signed main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
    srand(time(0));
    int n;cin>>n;
    vector<node>v(n);
    for(int i=0;i<n;++i){
        node pnt;cin>>pnt.x>>pnt.y;
        v[i]=pnt;
    }
    poly p(v);
    double s=p.area();
    double hs=s/2;
    vector<node>exnode(n);
    int sti=0;
    for(int i=0;i<n;++i){
        double si=0;
        for(int j=(i+1)%n,k=(i+2)%n;k!=i;){
            double t=(p.pnt[j]-p.pnt[i])^(p.pnt[k]-p.pnt[i]);
            if(si<=s&&si+t>s){
                double nows=s-si;
                double h=dist(p.pnt[i],line(p.edge[j]));
                exnode[i]=p.pnt[j]+(p.pnt[k]-p.pnt[j]).e(nows/h);
                if(!i)sti=j;
                break;
            }
            si+=t;
            ++j,++k;
            if(j>=n)j-=n;
            if(k>=n)k-=n;
        }
    }
    vector<int>totalNode;
    totalNode.reserve(n+n);
    {
        int j = 0;
        while (exnode[j].on(p.edge[sti])) {
            ++j;
            if (j >= n)j -= n;
        }
        while (!(exnode[j].on(p.edge[sti]))) {
            ++j;
            if (j >= n)j -= n;
        }
        for (int i = sti, u = 0; u < n; ++u) {
            totalNode.push_back(i);
            while (exnode[j].on(p.edge[i])) {
                totalNode.push_back(n + j);
                ++j;
                if (j >= n)j -= n;
            }
            ++i;
            if (i >= n)i -= n;
        }
    }
    auto getpnt=[&](int t){return (t<n?v[t]:exnode[t-n]);};
    auto getati=[&](int t){return (t>=n?v[t-n]:exnode[t]);};
    double ans_max=0,ans_min=inf;
    for(int i=0;i<n+n;++i){
        int j=(i+1)%(n+n);
        node p1(getpnt(totalNode[i])),p2(getpnt(totalNode[j]));
        if(zero(p1-p2))continue;
        node p3(getati(totalNode[i])),p4(getati(totalNode[j]));
        auto f_min=[&](double x){
            node pp=p1+(p2-p1)*x;
            line lp1q(p1,p3-pp);
            node pq=lp1q*line(p3,p4-p3);
            return dist(pp,pq);
        };
        ans_max=max({ans_max, dist(p1,p3),dist(p2,p4)});
        ans_min=min(ans_min,halfgo(f_min));
    }

    cout<<fixed<<setprecision(8)<<ans_min<<'\n'<<ans_max<<'\n';
    return 0;
}