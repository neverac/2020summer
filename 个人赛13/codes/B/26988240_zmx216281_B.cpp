#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
string a[25];
int main(){
   int n;
   cin >> n;
   double x,y,z;
   double m = 1e9;
   for(int i=1;i<=n;i++){
       cin >> x >> y >> z;
       m = min(m,sqrt(x*x+y*y+z*z));
   }
   cout << fixed << setprecision(3) << m << endl;
}