#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

int n;
char s[106];

int main(){
    int now=0,mn=0;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i){
        if(s[i]=='-')
            --now;
        else
            ++now;
        mn=min(mn,now);
    }
    printf("%d\n",now-mn);

    //while(1);
}
