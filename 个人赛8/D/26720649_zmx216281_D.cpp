#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int t,n,pos;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        cout << s << endl;
        for(int i=0;i<n;i++){
            scanf("%d",&pos);
            if(s[pos]=='a'){
                s[pos]='b';
            }
            else{
                s[pos]='a';
            }
            cout << s << endl;
        }
    }
}