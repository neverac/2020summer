#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#define ll long long
#define N 300006
using namespace std;

int T,len,len1,len2,s1[N],s2[N];
char s[N];

int main(){
    int now1,now2;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        len=strlen(s);
        len1=0; len2=0;
        for(int i=0;i<len;++i){
            if((s[i]-'0')&1)
                s1[++len1]=s[i]-'0';
            else
                s2[++len2]=s[i]-'0';
        }
        now1=1; now2=1;
        while(now1<=len1||now2<=len2){
            if(now1<=len1&&now2<=len2){
                if(s1[now1]>s2[now2]){
                    printf("%d",s2[now2]);
                    ++now2;
                }
                else{
                    printf("%d",s1[now1]);
                    ++now1;
                }
            }
            else if(now1<=len1){
                printf("%d",s1[now1]);
                ++now1;
            }
            else{
                printf("%d",s2[now2]);
                ++now2;
            }
        }
        cout<<'\n';
    }
    //while(1);
}
