#include <iostream>

using namespace std;
unsigned long long a,b,ans,temp;

int main()

{   cin>>a>>b;
    ans=0;
    while(a%b!=0){
        if(a>b){
            ans+=a/b;
            a=a%b;
        }
        while(a<b){
            temp=b;
            b=a;
            a=temp;
        }
    }
    ans+=a/b;
    cout<<ans<<endl;

    return 0;
}
