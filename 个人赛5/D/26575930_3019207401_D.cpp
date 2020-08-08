#include <iostream>

using namespace std;
int t;
long long n,k,ans;
long long dfs(long long a,long long b){
   long long c=a%b;
   return (a-c)/b;
}
int main()
{   cin>>t;
    while(t--){
        cin>>n>>k;
        ans=k;
        if(n>k){
            cout<<k<<endl;
        }
        else
        {
            ans=k+k/(n-1);
            if(k%(n-1)==0){
                ans--;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
