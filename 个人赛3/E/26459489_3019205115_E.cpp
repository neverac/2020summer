#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
int main()
{
    int n;
    cin >>n;
    char op;
    int p[101];
    for(int i=0;i<n;i++){
        cin >>op;
        if(op=='-'){
            p[i]=-1;
        }
        else{
            p[i]=1;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+p[i]<0){
            continue;
        }
        else{
            sum += p[i];
        }
    }
    cout <<sum<<endl;
    return 0;
}*/


long long f[100005][2]={0};
int h1[100005],h2[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d",&h1[i]);
    for(int i=1;i<=n;i++)
    scanf("%d",&h2[i]);
    for(int i=1;i<=n;i++)
    {
    	f[i][0]=max(f[i-1][1]+h1[i],f[i-1][0]);
    	f[i][1]=max(f[i-1][0]+h2[i],f[i-1][1]);
    }
    printf("%lld\n",max(f[n][0],f[n][1]));
    return 0;
}
