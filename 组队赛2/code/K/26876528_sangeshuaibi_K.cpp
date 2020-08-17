#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

int T,n;
priority_queue<int,vector<int>,greater<int> > q;

int main(){
    int temp,ans,t1,t2;
    scanf("%d",&T);
    while(T--){
        while(!q.empty())
            q.pop();
        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&temp);
            q.push(temp);
        }
        while(!q.empty()){
            t1=q.top();
            q.pop();
            if(q.empty())
                break;
            t2=q.top();
            q.pop();
            ans+=(t1+t2);
            q.push(t1+t2);
        }
        printf("%d\n",ans);
    }
    //while(1);
}
