#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
 
const int maxn=1e5+100;
ll a[maxn],bit[maxn],n,zheng[maxn],fan[maxn],nn;
 
ll lowbit(ll x)
{
    return x&(-x);
}
ll sum(ll x)
{
    ll s=0;
    while (x>0) {
        s+=bit[x];
        x-=lowbit(x);
    }
    return s;
}
void add(ll x,ll val)
{
    while (x<=nn) {
        bit[x]+=val;
        x+=lowbit(x);
    }
}
int main()
{
    scanf("%lld",&n);
    nn=-1;
    for (int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        nn=max(nn,a[i]);
    }
    ll ans=0;
    for (int i=0;i<n;i++) {
        zheng[i]=i-sum(a[i]);
        add(a[i],1);
    }
    // for(int i=0;i<n;i++)printf("%d ",zheng[i]);
    // if(ans==0){
    //     printf("0\n");
    //     return 0;
    // }
    memset(bit,0,sizeof(bit));
 
    for (int i=n-1;i>=0;i--) {
        fan[i]=n-i-1-sum(a[i]);
        add(a[i],1);
        ans+=min(fan[i],zheng[i]);
    }
    
        // cout<<endl;
    // if(ans==0){
    //     printf("0\n");
    //     return 0;
    // }
    // fan[n]=0;
    // ans=fan[0];
    // for(int i=1;i<=n;i++){
    //      printf("%lld %lld \n",zheng[i-1],fan[i]);
    //     ans=min(ans,zheng[i-1]+fan[i]);
    // }
    printf("%lld\n",ans);
    return 0;
}
