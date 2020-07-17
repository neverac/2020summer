#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll N; scanf("%lld", &N);
    // 26 26 * 26 26 * 26 * 26
    ll pre[12] = {0};
    ll sum = 26;
    for(int i = 1; i <= 11; i++){
        pre[i] = pre[i - 1] + sum;
        sum = sum * 26;
    }
    int cur = 11;
    // pre[i - 1] + 1 ~ pre[i]
    // a = 0
    while(N < pre[cur] + 1){
        cur--;
    }
    N -= pre[cur];
    --N;
    int stk[13];
    for(int i = 1; i <= cur + 1; i++){
        stk[i] = N % 26;
        N /= 26;
    }
    for(int i = cur + 1; i >= 1; i--){
        printf("%c", (char)('a' + stk[i]));
    }
    return 0;
}