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
int n,q,b,c;
int a[1000005];
long long int ans,ji;

int main()
{
    cin>>n;
    ans = 0;
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
    {
        cin>>ji;
        ans += ji;
        a[ji]++;
    }


    cin>>q;
    while(q--)
    {
        cin>>b>>c;
        int j = c-b;
        ans += (j*a[b]);
        a[c] += a[b];
        a[b] = 0;

        cout<<ans<<endl;
    }


    return 0;
}
