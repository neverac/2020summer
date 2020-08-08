#include <iostream>
using namespace std;
int A[105],B[105],len1,len2;
int main(){
    int n;
    cin>>n;
    for(int i=n;i>=1;i--){
        cin>>A[i];
    }
    for(int i=n;i>=1;i--){
        cin>>B[i];
    }
    len1=len2=n;
    while(len1*len2!=0){
        if(A[len1]>B[len2]){
            len2--;
        }else{
            len1--;
        }
    }
    cout<<len1+len2;
    return 0;
}