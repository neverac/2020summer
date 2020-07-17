#include <bits/stdc++.h>

using namespace std;
int  a[10000];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    int ant=0;
    for(int i=0;i<k;i++){
        ant+=a[i];
    }
    cout<<ant;
}