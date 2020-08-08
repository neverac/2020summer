#include <iostream>
using namespace std;
int main(){
    int n,k,x;
    cin>>n>>k;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>x;
        sum+=x/k+(x%k!=0);
    }
    cout<<sum/2+(sum%2!=0);
    return 0;
}