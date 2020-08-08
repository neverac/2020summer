#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,cnt,w[150005];
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        cnt=0;
        for(int i=0;i+2<s.size();i++){
            if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e'){
                w[cnt++]=i+2;
                i+=2;
            }
            if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'){
                if(i+4<s.size()&&s[i+3]=='n'&&s[i+4]=='e'){
                    w[cnt++]=i+3;
                    i+=4;
                }else{
                    w[cnt++]=i+2;
                    i+=2;
                }
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++){
            printf("%d ",w[i]);
        }
        printf("\n");
    }
    return 0;
}