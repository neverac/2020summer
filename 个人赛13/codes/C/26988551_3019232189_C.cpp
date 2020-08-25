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
#define N 100006
using namespace std;

int n,m,ind[1006],len[1006],sta[1006],cnt,ans;
string s[1006];

bool cmp(int x,int y){
    return s[x]<s[y];
}

bool cmp1(int x,int y){
    return len[x]<len[y];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        cin>>s[i];
        len[i]=s[i].length();
        ind[i]=i;
    }
    sort(ind+1,ind+1+m,cmp);
    sta[++cnt]=ind[1];
    for(int i=2;i<=m;++i)
        if(s[ind[i]]!=s[ind[i-1]])
            sta[++cnt]=ind[i];
    sort(sta+1,sta+1+cnt,cmp1);
    if(len[sta[1]]<=n){
        ++ans;
        n-=len[sta[1]];
    }
    for(int i=2;i<=cnt;++i)
        if(len[sta[i]]+1<=n){
            ++ans;
            n-=(len[sta[i]]+1);
        }
    printf("%d",ans);
   // while(1);
}
