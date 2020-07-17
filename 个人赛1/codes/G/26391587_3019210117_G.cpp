#include <iostream>
#include <algorithm>
using namespace std;
long long int n,m,k,ans,mod=1e9+7,g[101010],b[101010],i;
int main(){
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    for(i=0;i<m;i++){
        cin>>g[i];
    }
    sort(b,b+n);
    sort(g,g+m);
    if(b[n-1]>g[0]){
        cout<<"-1";
        return 0;
    }
    for(i=0;i<n;i++){
        ans+=b[i];
    }
    ans*=m;
    for(i=1;i<m;i++){
        ans+=g[i]-b[n-1];
    }
    if(g[0]!=b[n-1]){
        ans+=g[0]-b[n-2];
    }
    cout<<ans;
    return 0;
}