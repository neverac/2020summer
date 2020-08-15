#include <iostream>
#include <string>
using namespace std;
string s1,s2;
int dp[4005][4005],pre[4005][4005],nxts1[4005][2],nxts2[4005][2],s1len,s2len;
int dpsear(int len1,int len2){
    if(len1==s1.size()&&len2==s2.size()){
        return 0;
    }
    if(dp[len1][len2]!=0){
        return dp[len1][len2];
    }
    int res1=dpsear(nxts1[len1][0],nxts2[len2][0]),res2=dpsear(nxts1[len1][1],nxts2[len2][1]);
    if(res1<=res2){
        pre[len1][len2]=-1;
        dp[len1][len2]=res1+1;
    }else{
        pre[len1][len2]=1;
        dp[len1][len2]=res2+1;
    }
    return dp[len1][len2];
}
void getans(int len1,int len2){
    if(len1==s1.size()&&len2==s2.size()){
        return;
    }
    int nxt=(pre[len1][len2]>0);
    printf("%d",nxt);
    getans(nxts1[len1][nxt],nxts2[len2][nxt]);
}
void sol(){
    cin>>s1>>s2;
    s1len=s1.size();
    s2len=s2.size();
    s1=" "+s1;
    s2=" "+s2;
    for(int i=0;i<=s1len;i++){
        for(int j=0;j<=s2len;j++){
            dp[i][j]=0;
        }
    }
    //cout<<s1<<"|"<<s2<<"|\n";
    nxts1[s1.size()][0]=nxts1[s1.size()][1]=s1.size();
    nxts2[s2.size()][0]=nxts2[s2.size()][1]=s2.size();
    for(int i=s1len;i>=0;i--){
        nxts1[i][1]=nxts1[i+1][1];
        nxts1[i][0]=nxts1[i+1][0];
        nxts1[i][s1[i+1]=='1']=i+1;
    }
    for(int i=s2len;i>=0;i--){
        nxts2[i][1]=nxts2[i+1][1];
        nxts2[i][0]=nxts2[i+1][0];
        nxts2[i][s2[i+1]=='1']=i+1;
    }
    dpsear(0,0);
    getans(0,0);
    // for(int i=0;i<=s1len;i++){
    //     for(int j=0;j<=s2len;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
int main(){
    //freopen("in.txt","r",stdin);
    sol();
    return 0;
}