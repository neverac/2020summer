#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int p[1005];
    int k,n;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(p,p+n);
    for(int i=1;i<k;i++){
        p[i]+=p[i-1];
    }
    cout<<p[k-1];
    return 0;
}