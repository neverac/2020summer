#include <iostream>
#include <algorithm>
using namespace std;
int a[200005];
int main(){
	int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<2*n;i++){
        scanf("%d",a+i);
    }
    sort(a,a+2*n);
    long long int x=a[n-1]-a[0],y=a[2*n-1]-a[n],ans=x*y;
    x=a[2*n-1]-a[0];
    for(int i=1;i<n;i++){
        y=a[i+n-1]-a[i];
        ans=min(ans,x*y);
    }
    printf("%lld",ans);
}