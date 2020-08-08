#include <iostream>
#include <cmath>
using namespace std;
int n,a[200005],l[200005],r[200005],ans=1;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        l[i]=r[i]=1;
    }
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            l[i]=l[i-1]+1;
        }
        ans=max(ans,l[i]);
    }
    for(int i=n-1;i>=1;i--){
        if(a[i]<a[i+1]){
            r[i]=r[i+1]+1;
        }
        ans=max(ans,r[i]);
    }
    for(int i=1;i<=n-2;i++){
        if(a[i]<a[i+2]){
            ans=max(ans,l[i]+r[i+2]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<l[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<r[i]<<" ";
    // }
    // cout<<endl;
    printf("%d",ans);
    return 0;
}