#include <iostream>
#include <cmath>
using namespace std;
long long n,k,ans,cnt;
int lis[100005];
int main()
{   cin>>n>>k;
    ans=0;
    cnt=0;
    for(int i=0;i<n;i++){
        cin>>lis[i];
        cnt+=lis[i]/k;
        if(lis[i]%k>0)cnt++;
    }
    cout<<cnt/2+cnt%2<<endl;
    return 0;
}
