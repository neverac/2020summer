#include <iostream>
#include <string.h>
using namespace std;

char str [200];
int main()
{
    int n;
    cin>>n;
    cin>>str;
    int num=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(str[i]=='+'){
            num++;
        }
        else {
            if(num>0){
                num--;
            }
            else ans++;
        }
    }
    for(int i=0;i<n;i++){
        if(str[i]=='+'){
            ans++;
        }
        else ans--;
    }
    cout<<ans<<endl;
    return 0;
}
