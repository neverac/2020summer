#include <iostream>
#include <algorithm>
using namespace std;
int cnt[100005]={0};
int main(){
    long long int n,q,a,b,c,sum=0;
    cin>>n;
    while(n--){
        cin>>a;
        cnt[a]++;
        sum+=a;
    }
    cin>>q;
    while(q--){
        cin>>b>>c;
        sum+=(c-b)*cnt[b];
        cnt[c]+=cnt[b];
        cnt[b]=0;
        cout<<sum<<endl;
    }
    return 0;
}