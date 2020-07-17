#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{  int n,k;
   cin>>n>>k;
   vector<int> value;
   for(int i=0;i<n;i++){
     int a1;
     cin>>a1;
     value.push_back(a1);
   }
   sort(value.begin(),value.begin()+n);
   int sum=0;
   for(int i=0;i<k;i++){
    sum=sum+value[i];
   }
   cout<<sum<<endl;
   return 0;
}
