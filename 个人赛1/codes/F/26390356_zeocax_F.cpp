#include <iostream>
#define ll long long
using namespace std;
ll cnt[100100];
int main(){
    int N; scanf("%d", &N);
    ll sum = 0;
    for(int i = 1; i <= N; i++){
        int A; scanf("%d", &A);
        ++cnt[A];
        sum += A;
    }
    int Q; scanf("%d", &Q);
    for(int i = 1; i <= Q; i++){
        int B, C; scanf("%d%d", &B, &C);
        sum -= cnt[B] * B;
        sum += cnt[B] * C;
        cnt[C] += cnt[B];
        cnt[B] = 0;
        printf("%lld\n", sum);
    }
    return 0;
}