#include <iostream>
#include <cstdio>
#include <cmath>
#define INF 0x7fffffffffffffff
using namespace std;

//double x2,x3,y2,y3,h,a,k,b;
////long long lsl,ovo,x,y,m,n,l,r,mid;
//bool isOK(){
//  return (mid - m -n -mid/x/y >= (lsl > m ? lsl - m : 0) + (ovo > n ? ovo - n : 0));
//}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=n;i>m;i--) {
        cout << i << ' ';
    }
    int flag = -1;
    for (int i = m+1;m;m--)
    {
        i = i + flag * m;
        flag = flag - 1 ? 1 : -1;
        cout << i << ' ';
    }
}