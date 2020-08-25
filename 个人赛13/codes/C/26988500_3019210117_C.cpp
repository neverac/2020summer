#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
set<string>words;
int lenarr[1005],len=0;
int main(){
    words.clear();
    int n,m,ans=0;
    string s;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        cin>>s;
        words.insert(s);
    }
    for(string i:words){
        lenarr[len++]=i.size();
    }
    sort(lenarr,lenarr+len);
    if(lenarr[0]<=n){
        ans++;
        n-=lenarr[0];
    }
    for(int i=1;i<len;i++){
        if(lenarr[i]+1<=n){
            ans++;
            n-=(lenarr[i]+1);
        }
    }
    printf("%d",ans);
    return 0;
}