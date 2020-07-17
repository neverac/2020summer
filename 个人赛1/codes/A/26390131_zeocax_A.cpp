#include <iostream>
#include <algorithm>
using namespace std;
int p[1100];
int main(){
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; i++){
        scanf("%d", &p[i]);
    }
    sort(p + 1, p + N + 1);
    int ans = 0;
    for(int i = 1; i <= K; i++){
        ans += p[i];
    }
    printf("%d", ans);
    return 0;
}