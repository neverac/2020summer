#include <bits/stdc++.h>
using namespace std;

const int MAXN=5050;
typedef pair<int,int> pir;
int INF=~0U>>3;
map<int,int>mp; 
int f[MAXN][MAXN];
int n;
int a[5050];
void init(){
    cin>>n;
    for(int i =1 ;i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    return ; 
}

void solve(){
    int ans = 1;
    for(int i = 1; i <= n; i++){
        mp[a[i]]=i;
        for(int j = 1; j < i; j++){
            int d=a[i]-a[j];
            if(mp.find(a[j]-d)!=mp.end()) {
                int k=mp[a[j]-d];
                f[i][j]=f[j][k]+1;
            }else f[i][j]=1;
            ans=max(ans,f[i][j]+1);
        }
    }
    printf("%d\n", ans);
    return ;
}

int main()
{
//    printf("%d",sizeof(int)*5010*5010*2/1024);
    init();
    solve();

    return 0;
}