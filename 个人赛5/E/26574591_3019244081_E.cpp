//不会真的以为我不会吧，不会吧不会吧 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=(ll)1e9+7;
const int maxn=200005;
ll ans=0;
int trie[maxn*30][2],tot,n,a[maxn];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
ll exgcd(ll l,ll r,ll &x,ll &y)
{
    if(r==0){x=1;y=0;return l;}
    else
    {
        ll d=exgcd(r,l%r,y,x);
        y-=l/r*x;
        return d;
    }
}
void Insert(int x){
    int rt=0;
    for(int i=29;i>=0;i--){
        int now=(x>>i)&1;
        if(!trie[rt][now]) trie[rt][now]=++tot;
        rt=trie[rt][now];
    }
}
int Search(int x){
    int ans=0,rt=0;
    for(int i=29;i>=0;i--){
        int now=(x>>i)&1;
        if(trie[rt][now]){
            rt=trie[rt][now];
        }
        else{
            rt=trie[rt][now^1];
            ans|=(1<<i);
        }
    }
    return ans;
}
void dfs(int l,int r,int dep){
    if(dep==-1||l>=r) return ;
    int mid=l-1;
    while(mid<r&&((a[mid+1]>>dep)&1)==0) mid++;
 
    dfs(l,mid,dep-1);
    dfs(mid+1,r,dep-1);
    if(mid==l-1||mid==r) return ;
    for(int i=l;i<=mid;i++) {
        Insert(a[i]);
    }
    int tmp=INT_MAX;
    for(int i=mid+1;i<=r;i++) {
        tmp=min(tmp,Search(a[i]));
    }
    ans+=(ll)tmp;
    for(int i=0;i<=tot;i++) {
        trie[i][0]=trie[i][1]=0;
    }
    tot=0;
}
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
 
    dfs(1,n,29);
    printf("%lld\n",ans);
}