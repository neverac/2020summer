#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<cstdio>

using namespace std;
int  main()
{
    int n,k;
    cin>>n>>k;
    int x[1005];
    for(int i=0;i<n;++i)
    	cin>>x[i];
    sort(x,x+n);
    long long sum=0;
    for(int i=0;i<k;++i)
    	sum+=x[i];
    cout<<sum<<endl;
    return 0;
}

