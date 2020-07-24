#include <bits/stdc++.h>
using namespace std;
int k,n,s,p,tmp;
int main(){
    cin >> n >> k >> s >> p;
    tmp = k/s+1;
    if(k%s == 0) tmp --;
    tmp *= n;
    if(tmp%p == 0) printf("%d\n",tmp/p);
    else printf("%d\n",tmp/p+1);
    return 0;
}