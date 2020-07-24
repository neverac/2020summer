#include<bits/stdc++.h>
using namespace std;

inline int gcd(int a,int b) {
    while(b^=a^=b^=a%=b);
    return a;
}

int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--){
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        int gc = gcd(a,b);
        if((n/gc)%2 == 0){
            printf("Case #%d: Iaka\n",cas);
        }else{
            printf("Case #%d: Yuwgna\n",cas);
        }
        cas++;
    }
    return 0;
}
