#include <iostream>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    char x;
    while(n--){
        cin>>x;
        if(x=='+'){
            ans++;
        }
        if(x=='-'){
            if(ans!=0){
                ans--;
            }
        }
    }
    cout<<ans;
    return 0;
}