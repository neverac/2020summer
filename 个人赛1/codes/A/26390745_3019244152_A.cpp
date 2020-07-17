#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <stdio.h>
#include <vector>
#include <stack>
#include <iomanip>
const int SIZE = 1000005;

using namespace std;
int n,k;
int a[1005];


int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans = 0;
    for(int i=0;i<k;i++)
        ans += a[i];
    cout<<ans<<endl;

    return 0;
}
