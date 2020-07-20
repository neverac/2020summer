#include <iostream>
#include <cstdio>
#include <cmath>
#define INF 0x7fffffffffffffff
using namespace std;

double x2,x3,y2,y3,h,a,k,b;
long long lsl,ovo,x,y,m,n,l,r,mid;
bool isOK(){
  return (mid - m -n -mid/x/y >= (lsl > m ? lsl - m : 0) + (ovo > n ? ovo - n : 0));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    cin >> lsl >> ovo >> x >> y;
    l = 1, r = INF, mid = (l + r) / 2;
    while (l + 1 < r){
//        cout << 1;
        m = mid/y - mid/x/y;
        n = mid/x-mid/x/y;
        if (isOK())
            r = mid;
        else
            l = mid;
        mid = (l + r) / 2;
    }
    cout << r;
}