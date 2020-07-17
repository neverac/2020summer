#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
int main(){
    ll num;scanf("%lld",&num);
    while(num--){
        v.push_back(num%26);
        num/=26;
    }
    for(int i=v.size()-1;i>=0;i--) printf("%c",(char)(v[i]+'a'));
    return 0;
}