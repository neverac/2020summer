#include <bits/stdc++.h>
using namespace std;

const int INF=4010;
const int MAXN=4020;
char sa[MAXN],sb[MAXN];
int f[MAXN][MAXN],g[MAXN][MAXN];
int ha[MAXN][2],hb[MAXN][2],lena,lenb;
void machine(int h[MAXN][2],char a[MAXN],int n) {
    h[n+1][0]=h[n+1][1]=INF;
    for(int i=n;i>=1;--i) {
        h[i][0]=h[i+1][0];
        h[i][1]=h[i+1][1];
        h[i][a[i]]=i;
    }
}

bool cmp(const vector<int>&a,const vector<int>&b) {
    int lena=a.size();
    int lenb=b.size();
    int len=min(lena,lenb);
    for(int i=0;i<len;++i) {
        if(a[i]!=b[i])return a[i]<b[i];
    }return lena<lenb;
}
int next(const int h[MAXN][2],int i,int z) {
    if(i==INF)return INF;
    return h[i+1][z];
}
int dfs(int ra,int rb) {
    if(ra==INF&&rb==INF) {
        return 0;
    }
    if(f[ra][rb])return f[ra][rb];
    f[ra][rb]=INF;
    g[ra][rb]=-1;
    for(int p=0;p<2;++p) {
        int x=dfs(next(ha,ra,p),next(hb,rb,p))+1
        ;
        if(x<f[ra][rb]) {
            f[ra][rb]=x;
            g[ra][rb]=p;
        }
    }
  //  printf("[%d][%d]:=%d\n",ra,rb,f[ra][rb]);
    return f[ra][rb];
}
void print(int ra,int rb) {
    if(ra==INF&&rb==INF) {
        return ;
    }
    int p=g[ra][rb];
    printf("%d",p);
    print(next(ha,ra,p),next(hb,rb,p));
}
int main()
{
    scanf("%s%s",sa+1,sb+1);
    lena=strlen(sa+1);
    lenb=strlen(sb+1);
    for(int i=1;i<=lena;++i) {
        sa[i]-='0';
    }
    for(int i=1;i<=lenb;++i) {
        sb[i]-='0';
    }
    machine(ha,sa,lena);
    machine(hb,sb,lenb);
    dfs(0,0);
    print(0,0);
    return 0;
}