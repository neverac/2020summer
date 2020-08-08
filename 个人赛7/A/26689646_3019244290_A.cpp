#include <iostream>
#include <stdio.h>
#include<cmath>
#include<cctype>
#include<cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include<math.h>
#include<map>
#include<unordered_map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define Maxn 100005
#define ll long long
using namespace std;

char s[Maxn];
int p[27][Maxn]={0};

ll ans=0;
int main(){
    int k;
    scanf("%d",&k);
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=0;i<26;i++){
       int t=0; //字母出现的次数
       for(int j=1;j<=len;j++){
        if(s[j]-'a'==i){
            t++;
            p[i][t]=j;//记录每个字符出现的位置
        }
        if(!t)
            continue;
        if(t<=k)
            ans+=p[i][t];
        else{
            ans+=p[i][t]-p[i][t-k];
        }
       }
    }
    printf("%lld\n",ans);
    return 0;
}
