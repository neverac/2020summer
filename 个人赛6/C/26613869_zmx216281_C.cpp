#include<cstdio>
#include<iostream>
using namespace std;

int rec[100010];
int find(int x){
    if(x==rec[x])return rec[x];
    return rec[x]=find(rec[x]);
}
bool check(int x,int y){
    if(find(x)==find(y))return false;
    else{
        rec[find(x)]=find(y);
        return true;
    }
}
int main(){
    int n,k,f1,f2;
    int ans = 0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        rec[i]=i;
    }
    for(int i=0;i<k;i++){
        scanf("%d%d",&f1,&f2);
        if(!check(f1,f2))ans++;
    }
    cout << ans << endl;
}