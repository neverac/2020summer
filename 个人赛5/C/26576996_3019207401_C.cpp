#include <iostream>

using namespace std;
long long n,pos,ans;
long long dfs(long long a,long long b){
   long long c=a%b;
   return (a-c)/b;
}
int a[400];
int judge[400];
int main()
{   cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=0;a[0]=800;
    for(int i=0;i<=n;i++){
        if(a[i+1]>=a[i]){
            judge[i]=1;
        }
        else if(a[i+1]<a[i]){
            judge[i]=0;
        }
    }
    pos=0,ans=100;
    for(int i=1;i<=n;i++){
        if((judge[i-1]==0)&&(judge[i]==1)){
            if(ans>=a[i]){
                long long temp=dfs(ans,a[i]);
                if(temp>100000){
                    temp=100000;
                }
                pos=temp;
                ans-=temp*a[i];
            }
        }
        else if(judge[i]==0&&judge[i-1]==1){
            ans+=pos*a[i];
            pos=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
