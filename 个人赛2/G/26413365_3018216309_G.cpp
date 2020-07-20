#include <bits/stdc++.h>
using namespace std;

int const maxn=100001;
int a[maxn],interval[maxn];
bool flag[maxn];

int main(){
    int n,k;
    cin>>n>>k;
    memset(flag,0,sizeof(flag));
    flag[0]=true;
    flag[1]=true;
    a[0]=1;
    for(int i=1; i<k; i++) {
            interval[i] = n - i;
    }
    interval[k] = 1;
    int t=1;
    for(int i=1; i<n; i++){
        int t1=a[i-1]-interval[t],t2=a[i-1]+interval[t];
        if(t1>0&&!flag[t1]) {
                a[i] =t1;
                flag[t1] =true;
        }
        else{
            a[i] = t2;
            flag[t2] = true;
        }
        if(t<k) t++;
    }
    cout<<a[0];
    for(int i=1;i<n;++i){
        cout<<" "<<a[i];
    }
}
