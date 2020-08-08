#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    int ans = 0;
    cin>>n>>k;
    for(int i = 1; i <= n; i++) {
        int w;
        scanf("%d", &w);
        int num = w / k;
        if(w % k != 0) ++num;
        ans += num;
    }
    printf("%d\n", ans % 2 == 1 ? ans / 2 + 1 : ans / 2);

    return 0;
}