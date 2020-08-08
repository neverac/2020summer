#include <iostream>
#include <string>
using namespace std;
void sol(){
    string s;
    s.resize(55,'a');
    cout<<s<<endl;
    int x,n;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(s[x]=='a'){
            s[x]='b';
        }else{
            s[x]='a';
        }
        cout<<s<<endl;
    }
}
int main(){
   // freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        sol();
    }
    return 0;
}