
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn=2e5+5;
int n,a[maxn],l[maxn],r[maxn];
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        l[i]=1;
    for(int i=1;i<=n;i++)
        r[i]=1;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int maxlen=1;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]<a[i+1]){
            r[i]=r[i+1]+1;
        }
        maxlen=max(maxlen,r[i]);
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1]){
            l[i]=l[i-1]+1;
        }
        maxlen=max(maxlen,l[i]);
    }
    for(int i=1;i<=n-2;i++)
    {
        if(a[i]<a[i+2]){
            maxlen=max(maxlen,l[i]+r[i+2]);
        }
    }
    cout<<maxlen<<endl;
    return 0;
}