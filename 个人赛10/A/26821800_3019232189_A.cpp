#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
#define ll long long
#define N 200006
using namespace std;

int T,n,m;
int p[N],s[N],ind[N];

int a[N];
int mx[N*4];
inline void pushup(int x){
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
void build(int l,int r,int x){
    if(l>r){
        mx[x]=-1;
        return ;
    }
    if(l==r){
        mx[x]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,x<<1);
    build(mid+1,r,x<<1|1);
    pushup(x);
}
int qq(int L,int R,int l,int r,int x){
    if(l>r||l>R||r<L)
        return -1;
    if(l>=L&&r<=R)
        return mx[x];
    int mid=(l+r)>>1;
    return max(qq(L,R,l,mid,x<<1),qq(L,R,mid+1,r,x<<1|1));
}

bool cmp(int x,int y){
    return p[x]>p[y];
}

int getpos(int val){
    int temp=-1,l=1,r=m,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(p[ind[mid]]>=val){
            temp=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return temp;
}

bool check(int l,int r){
    int monq=qq(l,r,1,n,1),pos;
    pos=getpos(monq);
    if(pos==-1)
        return 0;
    if(s[ind[pos]]<r-l+1)
        return 0;
    return 1;
}

int work(){
    int ans=0,l,r,mid,temp;
    for(int i=1;i<=n;++i){
        l=i; r=n; temp=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(check(i,mid)){
                temp=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        if(temp==-1)
            return -1;
        i=temp;
        ++ans;
    }
    return ans;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        build(1,n,1);
        scanf("%d",&m);
        for(int i=1;i<=m;++i){
            scanf("%d%d",&p[i],&s[i]);
            ind[i]=i;
        }
        sort(ind+1,ind+1+m,cmp);
        for(int i=1;i<=m;++i)
            s[ind[i]]=max(s[ind[i]],s[ind[i-1]]);
        printf("%d\n",work());
    }
    //while(1);
}
