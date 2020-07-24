#include <iostream>
#include <algorithm>
using namespace std;
struct minion{
    long long int hp,dmg;
}t[200005];
bool cmp(minion a,minion b){
    return a.hp-a.dmg>b.hp-b.dmg;
}
int main(){
    int n,a,b;
    long long ans=0,sum=0;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&t[i].hp,&t[i].dmg);
    }
    sort(t+1,t+1+n,cmp);
    for(int i=1;i<=b;i++){
        sum+=max(t[i].hp,t[i].dmg);
    }
    for(int i=b+1;i<=n;i++){
        sum+=t[i].dmg;
    }
    ans=sum;
    for(int i=1;i<=b;i++){
        ans=max(ans,sum-max(t[i].hp,t[i].dmg)+(t[i].hp<<a));
    }
    sum=sum-max(t[b].hp,t[b].dmg)+t[b].dmg;
    if(b!=0){
        for(int i=b+1;i<=n;i++){
            ans=max(ans,sum-t[i].dmg+(t[i].hp<<a));
        }
    }
    printf("%lld",ans);
    return 0;
}