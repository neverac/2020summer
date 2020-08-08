#include <iostream>
#include <cmath>
#include <string>
using namespace std;
bool sol(){
    string s;
    cin>>s;
    int reslen=0;
    for(char xi='0';xi<='9';xi++){
        for(char xj='0';xj<='9';xj++){
            int tem=0;
            bool flag=1;
            if(xi==xj){
                for(int i=0;i<s.size();i++){
                    if(s[i]==xi){
                        tem++;
                    }
                }
            }else{
                for(int i=0;i<s.size();i++){
                    if(flag&&s[i]==xi){
                        flag=false;
                    }
                    if((!flag)&&s[i]==xj){
                        flag=true;
                        tem+=2;
                    }
                }
            }
            reslen=max(reslen,tem);
        }
    }
    printf("%d\n",s.size()-reslen);
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