#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,t,x;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        priority_queue<int,vector<int>,greater<int>>heap;
        for(int i =0;i<n;i++){
            scanf("%d",&x);
            heap.push(x);
        }
        int ans = 0;
        while(heap.size()>1){
            int a = heap.top();heap.pop();
            int b = heap.top();heap.pop();
            ans += (a+b);
            heap.push(a+b);
        }
        cout << ans << endl;
    }
}