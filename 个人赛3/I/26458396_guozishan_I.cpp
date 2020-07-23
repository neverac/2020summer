#include <iostream>

using namespace std;
char ch[100];

int main()
{
    int n;
    while(cin>>n){
            int s = 0;
    for(int i = 0 ; i <n ; i++){
        cin>>ch[i];
        if(ch[i] == '+'){
        s++;
        }else{
        if(s==0){
            s++;
        }
        s--;
    }
    //for(int i = 0; i < n ; i ++){
    //    if(ch[i] == '+'){
    //    s++;
    //    }else{
    //    s--;
    //}
    }
    //if(s<0){
    //    cout<<0<<endl;
    //}else{
    cout<<s<<endl;
    //}
    }
    return 0;
}
