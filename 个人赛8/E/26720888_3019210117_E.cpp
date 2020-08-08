#include <iostream>
#include <cmath>
using namespace std;
long long int a[100005],l[100005],r[100005],sum,maxl,maxr;
bool sol(){
    int n;
    scanf("%d",&n);
    l[0]=sum=r[n+1]=0;
    maxl=maxr=-1;
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        l[i]=max(a[i],l[i-1]+a[i]);
        if(i!=n){
            maxl=max(maxl,l[i]);
        }
        sum+=a[i];
    }
    for(int i=n;i>=2;i--){
        r[i]=max(a[i],r[i+1]+a[i]);
        maxr=max(maxr,r[i]);
    }
    return !(maxl>=sum||maxr>=sum);
}
int main(){
   // freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        if(sol()){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}