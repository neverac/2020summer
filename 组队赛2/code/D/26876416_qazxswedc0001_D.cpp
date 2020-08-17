#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    bool flag=false;
    for(int i=0;i<3;i++){
        cin>>s;
        if(s!="bubble"&&s!="tapioka"){
            cout<<s<<" ";
            flag=true;
        }
    }
    if(!flag){
        cout<<"nothing";
    }
    return 0;
}