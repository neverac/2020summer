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

char s[N];
int n;

int main(){
    ll ans=1;
    int temp;
    scanf("%s",s+1);
    n=strlen(s+1);
    temp=0;
    for(int i=1;i<=n;++i){
        temp*=10;
        temp+=(s[i]-'0');
        temp%=4;
    }
    if(temp==1)
        ans+=(2+3+4);
    else if(temp==2)
        ans+=(4+4+1);
    else if(temp==3)
        ans+=(3+2+4);
    else
        ans+=(1+1+1);
    ans%=5;
    cout<<ans;

    //while(1);
}
