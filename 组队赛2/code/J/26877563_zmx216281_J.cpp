#include<bits/stdc++.h>
using namespace std;
int n,m,t;
bitset<510>a[20];
string s;
int main(){
    scanf("%d",&t);
    while(t--){
        int ans=25;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            cin >> s;
            for(int j=0;j<n;j++){
                if(s[j]=='1') a[i][j]=1;
                else a[i][j]=0;
                
            }
        }
        int temp=1<<m;
        int rec;
        bool flag;
        for(int k=0;k<temp;k++){
            bitset<510>t;
            rec=0;
            flag=true;
            for(int i=0;i<n;i++){
                t[i]=0;
            }
            for(int i=0;i<m;i++){
                if(k&(1<<i)){
                    t|=a[i];
                    rec++;
                }
            }
            for(int i=0;i<n;i++){
                if(!t[i])flag=false;;
            }
            if(flag){
                ans=min(ans,rec);
            }
        }
        
        if(ans<=m){
            cout << ans << endl;
        }
        else cout << -1 << endl;
    }
}