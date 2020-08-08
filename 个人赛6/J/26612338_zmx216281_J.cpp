#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010];
int n,k;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    long long ans = 0;

    for(int i=0;i<n;i++){
        if(a[i]%k==0){
            ans+=a[i]/k;
        }
        else{
            ans+=(a[i]/k)+1;
        }
    }
    if(ans%2==0){
        cout << ans/2 << endl;
    }
    else{
        cout << ans/2+1 << endl;
    }
}
