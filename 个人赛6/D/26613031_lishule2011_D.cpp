#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
struct node{
    int x,y,s;
}a[maxn];
int sum[110][110][15];
int n,q,c;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> c;
    for (int i= 1;i<=n;i++){
        cin >> a[i].x >> a[i].y >> a[i].s;
        sum[a[i].x][a[i].y][a[i].s]++;
    }
    for (int i=1;i<=100;i++)
        for (int j = 1;j<=100;j++)
            for (int k = 0;k<=10;k++)
                sum[i][j][k] += sum[i-1][j][k] + sum[i][j-1][k] - sum[i-1][j-1][k];

    for (int j = 1;j<=q;j++){
        int t,x1,y1,x2,y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans=0;
        for (int i=0;i<=c;i++)
        {
            int cnt=(t+i)%(c+1);
            int tot =sum[x2][y2][i]-sum[x1-1][y2][i]-sum[x2][y1-1][i]+sum[x1-1][y1-1][i];
            ans+=cnt*tot;
        }
        cout << ans << endl;
    }

}
