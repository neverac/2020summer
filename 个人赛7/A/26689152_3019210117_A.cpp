#include<iostream>
#include<string>
using namespace std;
int pos[26][100005]={0};
string str;
long long ret=0;
int k;
int main(){
    scanf("%d",&k);
    cin>>str;
    for(int i=0;i<26;i++){
        int now=0;
        pos[i][now]=0;
        for(int j=0;j<str.size();j++){
            if(str[j]-'a'==i){
                now++;
                pos[i][now]=j+1;
            }
            if(now<=k){
                ret+=pos[i][now];
            }else{
                ret+=pos[i][now]-pos[i][now-k];
            }

        }
    }
    printf("%lld",ret);
    return 0;
}
