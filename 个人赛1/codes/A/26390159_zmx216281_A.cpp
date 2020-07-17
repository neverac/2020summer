#include<iostream>
#include<algorithm>
using namespace std;
int a[1010];
int main(){
    int n,b;
    int total = 0;
    cin >> n >> b;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=0;i<b;i++){
        total+=a[i];
    }
    cout << total;
}