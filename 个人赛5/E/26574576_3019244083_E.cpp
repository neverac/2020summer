#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=200005;
int trie[maxn*30][2],tot,n,a[maxn];
ll ans=0;
void insertt(int x){
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
        insertt(a[i]);
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
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
    n = read();
    for(int i = 1;i <= n;i++){
        a[i] = read();
    }
    sort(a+1,a+1+n);
 
    dfs(1,n,31);
    cout<<ans<<endl;
	return 0;
	//CF原题+牛客原题就别查重了 
}