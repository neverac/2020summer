
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=1e3+10;
int x1[maxn],x2[maxn];
int yy1[maxn],y2[maxn],cnt1,cnt2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=0;j<m;j++)
            if (s[j] == '1') x1[++cnt1] = i,yy1[cnt1] =j+1;
            else if (s[j] == '2') x2[++cnt2] = i,y2[cnt2] =j+1;
    }
//    for (int i =1;i<=cnt1;i++) cout << x1[i] <<' '<<yy1[i] << endl;
    int ans =INF;
    for (int i=1;i<=cnt1;i++)
        for (int j=1;j<=cnt2;j++){
            int x=abs(x1[i]-x2[j])+abs(yy1[i]-y2[j]);
            if (x<ans) ans =x;
        }
    cout << ans+1;
    return 0;
}

