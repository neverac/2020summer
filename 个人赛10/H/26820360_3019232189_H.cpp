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

int n,ans;
int a[366];

int main(){
    ans=100000;
    scanf("%d",&n);
    a[0]=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j){
            ans=min(ans,abs(a[j]-a[i-1]-180)*2);
        }
    cout<<ans;
    //while(1);
}
