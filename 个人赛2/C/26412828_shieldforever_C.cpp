#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[30];

LL solve(){
    int n = strlen(s + 1);
    LL x5 = 0, ans = LONG_LONG_MIN;
    
    LL o = 1LL;
    for(int i = n; i >= 5 && i >= n - 2; i--){
        // x5 = x5 * 10 + s[i] - '0';
        x5 += o * (s[i] - '0');
        o *= 10LL;

        LL x4 = s[i - 1] - '0';
        LL x3 = s[i - 2] - '0';
        
        LL sum = 1LL;

        LL x1 = 0LL, x2 = 0LL;
        for(int j = 2; j <= i - 3; j++) x2 = x2 * 10LL + (s[j] - '0');
        x1 = s[1] - '0';
        sum = x1 + x2 - x3 * x4 / x5;
        // cout<<x1<<' '<<x2<<' '<<x3<<' '<<x4<<' '<<x5<<endl;
        if(sum > ans) ans = sum;

        x1 = 0LL, x2 = 0LL;
        for(int j = 1; j <= i - 4; j++) x1 = x1 * 10LL + (s[j] - '0');
        x2 = s[i - 3] - '0';
        sum = x1 + x2 - x3 * x4 / x5;
        // cout<<x1<<' '<<x2<<' '<<x3<<' '<<x4<<' '<<x5<<endl;
        if(sum > ans) ans = sum;
    }
    return ans;
}

int main(){
    int T;
    cin>>T;
    int c = 0;
    while(T--){
        scanf("%s", s + 1);
        printf("Case #%d: %lld\n", ++c, solve());
    }
    return 0;
}