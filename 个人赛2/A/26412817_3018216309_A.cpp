#include <bits/stdc++.h>
using namespace std;

int wall[51][51];
int nb,dx;
bool flag[51][51];
int num=0,biggest=0;
int tem;

void searchroom(int a[51][51],int i,int j){
    if(i<0||i==nb||j<0||j==dx||flag[i][j]) return;
    else{
        tem++;
        flag[i][j]=true;
        if((a[i][j]&1)==0) searchroom(a,i,j-1);
        if((a[i][j]&2)==0) searchroom(a,i-1,j);
        if((a[i][j]&4)==0) searchroom(a,i,j+1);
        if((a[i][j]&8)==0) searchroom(a,i+1,j);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(wall,0,sizeof(wall));
    memset(flag,0,sizeof(flag));
    cin>>nb>>dx;
    for(int i=0;i<nb;++i){
        for(int j=0;j<dx;++j){
            cin>>wall[i][j];
        }
    }
    for(int i=0;i<nb;++i){
        for(int j=0;j<dx;++j){
            if(flag[i][j]) continue;
            else{
                num++;
                tem=0;
                searchroom(wall,i,j);
                biggest=biggest>tem?biggest:tem;
            }
        }
    }
    cout<<num<<endl<<biggest<<endl;
}
