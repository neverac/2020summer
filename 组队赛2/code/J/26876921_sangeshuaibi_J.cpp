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
#include <bitset>
#define ll long long
#define N 100006
using namespace std;

int T,n,m;

bitset<506> a[20],b,c;
char s[506];
int ans,now;

void dfs(int pos){
    if(c==b)
        ans=min(ans,now);
    if(pos>m)
        return ;
    bitset<506> temp=c;
    //cout<<c<<endl;
    for(int i=pos;i<=m;++i){
        //printf("i=%d\n",i);
        c|=a[i];
        ++now;
        dfs(i+1);
        c=temp;
        --now;
    }
}

int main(){
    int len;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;++i){
            a[i].reset();
            scanf("%s",s);
            len=strlen(s);
            for(int j=0;j<len;++j)
                a[i][j]=s[j]-'0';
        }
        b.reset();
        for(int i=0;i<len;++i)
            b[i]=1;
        now=0;
        ans=1e9;
        c.reset();
        dfs(1);
        if(ans==1e9)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    //while(1);
}
/*
5 
3 3 
100 
011 
111 
5 6 
10000 
01001 
01110 
00111 
10110 
00101 
6 7 
000010 
011000 
100100 
001000 
000010 
010000 
110001 
7 6 
1001001 
1001000 
0001101 
0010110 
0110011 
0100001 
2 1 
01
*/