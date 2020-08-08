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

int k;
char s[N];
int sta[N],he,len;

int main(){
    ll ans=0;
    int now;
    scanf("%d%s",&k,s+1);
    len=strlen(s+1);
    for(int i=0;i<26;++i){
        he=0;
        for(int j=1;j<=len;++j)
            if(s[j]==i+'a')
                sta[++he]=j;
        sta[0]=0;
        sta[he+1]=len+1;
        for(int j=1;j<=k;++j){
            for(int l=1;l<=he;++l){
                if(l+j-1>he)
                    break;
                ans+=(sta[l]-sta[l-1])*(sta[l+j]-sta[l+j-1]);
            }
        }
    }
    cout<<ans;
    //while(1);
}
