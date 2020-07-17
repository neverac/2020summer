#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<cstdio>
using namespace std;
int A[100005];
int B[100005];
int C[100005];
int book[100005];
int  main()
{
    int n;
    cin>>n;
    long long sum=0;
    for(int i=0;i<n;++i)
    	{
    		cin>>A[i];
    		sum+=A[i];
    		book[A[i]]++;
    	}
    int m;
    cin>>m;
    for(int i=0;i<m;++i)
    	{
    		cin>>B[i]>>C[i];
    		sum=sum+book[B[i]]*(C[i]-B[i]);
    		cout<<sum<<endl;
    		book[C[i]] += book[B[i]];
    		book[B[i]]=0;
    	}

    return 0;
}

