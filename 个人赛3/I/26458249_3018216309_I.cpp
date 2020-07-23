#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    int minn=0,cnt=0;
    for(int i=0;i<s.length();++i){
        if(s[i]=='+'){
            cnt++;
        }
        else{
            cnt--;
            if(cnt<minn) minn=cnt;
        }
    }
    if(minn>=0)printf("%d",cnt);
    else{
        minn*=-1;
        printf("%d",minn+cnt);
    }
}
