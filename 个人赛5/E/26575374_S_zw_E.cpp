#include<stdio.h>
#include<string.h>
#include<string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#define ll long long 
#define N 200005
//#define mid (l+r)/2
#define lc (x<<1)
#define rc (x<<1)|1
#define tozero(x) memset(x,0,sizeof x);
#define INF 0x3f3f3f3f
using namespace std;

int n;
ll ans=0;
int trie[N*30][2],cnt = 0,a[N];

void Insert(int x){
    int root=0;
    for(int i=29;i>=0;i--){
        int tmp=(x>>i)&1;
        if(!trie[root][tmp]) trie[root][tmp]=++cnt;
        root=trie[root][tmp];
    }
}

int Search(int x){
    int ans=0,root=0;
    for(int i=29;i>=0;i--){
        int tmp=(x>>i)&1;
        if(trie[root][tmp]){
            root=trie[root][tmp];
        }
        else{
            root=trie[root][tmp^1];
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
    int tmp=INF;
    for(int i=mid+1;i<=r;i++) {
        tmp=std::min(tmp,Search(a[i]));
    }
    ans+=(ll)tmp;
    for(int i=0;i<=cnt;i++) {
        trie[i][0]=trie[i][1]=0;
    }
    cnt=0;
}

int main (){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    dfs(1,n,29);
    printf("%lld",ans);
    return 0;
}