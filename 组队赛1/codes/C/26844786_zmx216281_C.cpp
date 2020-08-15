#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
const int N=500010;
int d[N];
int main(){
    int r,s,p;
    scanf("%d%d%d",&r,&s,&p);
    r++,s++;
    int x,y;
    for(int i=1;i<=p;i++){
        scanf("%d%d",&x,&y);
        if(y>=s)y++;
        d[i]=(r-x)+abs(s-y);
    }
    sort(d+1,d+1+p);
    for(int i=2;i<=p;i++){
        if(d[i]<=d[i-1]){
            d[i]=d[i-1]+1;
        }
    }
    cout << d[p] << endl;
}