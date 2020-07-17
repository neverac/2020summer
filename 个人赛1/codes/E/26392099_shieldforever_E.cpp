#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
int s[100000];
int main(){
    scanf("%lld", &n);
    LL x = 0, y = 1, z = 0;
    while(x <= n){
        y *= 26LL;
        x += y;
        ++z;
    }
    x -= y;
    if(n == x){
        for(int i = 1; i < z; i++) cout<<'z';
        cout<<endl;
    }
    else{
        
        int u = 0;
        LL a = n - x - 1LL;
        while(a > 0){
            s[++u] = a % 26LL;
            a /= 26LL;
        }
        for(int i = z; i >= 1; i--) printf("%c", s[i] + 'a');
        cout<<endl;
    }
    return 0;
}