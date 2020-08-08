#include <bits/stdc++.h>
using namespace std;
vector<int> a[1005],b[1005];
char s[1005];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        //cout<<1<<endl;
        for(int j=0;j<m;j++){
            if(s[j]=='1') a[j].push_back(i);
            else if(s[j]=='2') b[j].push_back(i);
        }
    }
    int ans=1000005;
    for(int i=0;i<m;i++){
        if(a[i].size()==0) continue;
        for(int j=0;j<m;j++){
            if(b[j].size()==0) continue;
            int p1=0,p2=0;
            while(p1<a[i].size()&&p2<b[j].size()){
                if(a[i][p1]<b[j][p2]){
                    ans=min(ans,abs(i-j)+b[j][p2]-a[i][p1]+1);
                    p1++;
                }
                else if(a[i][p1]>b[j][p2]){
                    ans=min(ans,abs(i-j)+a[i][p1]-b[j][p2]+1);
                    p2++;
                }
                else{
                    ans=min(ans,abs(i-j)+1);
                    p1++,p2++;
                }
            }
            while(p1<a[i].size()){
                //cout<<abs(i-j)+b[j][p2-1]-a[i][p1]+1<<endl;
                ans=min(ans,abs(i-j)+a[i][p1]-b[j][p2-1]+1);
                //cout<<1<<endl;
                p1++;
                //cout<<p1<<endl;
            }
            //cout<<1<<endl;
            while(p2<b[j].size()){
                //cout<<abs(i-j)+a[i][p1-1]-b[j][p2]<<endl;
                ans=min(ans,abs(i-j)+b[j][p2]-a[i][p1-1]+1);
                p2++;
            }
            //cout<<i<<" "<<j<<" "<<ans<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}