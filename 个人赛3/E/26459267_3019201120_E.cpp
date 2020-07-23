#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int l[N];
int r[N];
int n;
ll sum1[N];
ll sum2[N];
ll cas1,cas2,cas3,cas4,cas5,cas6;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&l[i]);
    for(int i=1;i<=n;i++) scanf("%d",&r[i]);
    sum1[1]=l[1];
    sum2[1]=r[1];
    sum1[2]=r[1]+l[2];
    sum2[2]=l[1]+r[2];
    for(int i=3;i<=n;i++)
    {
        cas1=sum2[i-1]+l[i];
        cas2=sum2[i-2]+l[i];
        sum1[i]=max(cas1,cas2);
        cas4=sum1[i-2]+r[i];
        cas3=sum1[i-1]+r[i];
        sum2[i]=max(cas3,cas4);
    }
    cout<<max(sum1[n],sum2[n])<<endl;
}