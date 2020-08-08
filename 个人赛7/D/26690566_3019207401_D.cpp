#include <iostream>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
int m,n;
ll ans,num,temp,cnt;
int main()
{   int n;
    cin>>n;
    for(int j=0;j<n;j++){
        cin>>num;
        ans=1;
        while(num%2==0){
            num/=2;
        }
        for(ll int i=3;i<=7;i+=2){
            temp=1;
            cnt=1;
            while(num%i==0){
                num/=i;
                temp*=i;
                cnt+=temp;
            }
            ans*=cnt;
        }
        cout<<ans<<endl;

    }
    return 0;
}
