#include<bits/stdc++.h>
using namespace std;

#define N 1010
int a[N], b[N], n;

int main(){
    cin>>n;
    int ma = 0, mb = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &b[i]);
    }
    int i = 1, j = 1;
    while(i <= n && j <= n){
        if(a[i] < b[j]) i++;
        else j++;
    }
    cout<<n - i + 1 + n - j + 1<<endl;

    return 0;
}