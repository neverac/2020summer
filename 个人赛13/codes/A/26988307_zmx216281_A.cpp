#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
string a[25];
int main(){
   int t;
   cin >> t;
   long long n,m,x,y;
   for(int i=1;i<=t;i++){
       cin >> n >> m >> x >> y;
       if(x<=y)cout << m << endl;
       else{
           long long tem = n+(m-1)*y;
           cout << min(tem/x,m) << endl;
       }
   }
}