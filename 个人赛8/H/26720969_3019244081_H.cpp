#include<bits/stdc++.h>
/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime> 
*/
#define ll long long
using namespace std; 
const int N=1e5 + 100;
const double eps=1e-10;
int a[2*N],l[2*N],r[2*N]; 

int main(){
	int n;
    scanf("%d",&n); 
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
		l[i]=1,r[i]=1;
	}
    int ans=1;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]<a[i+1]){
            r[i]=r[i+1]+1;
        }
        ans=max(ans,r[i]);
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1]){
            l[i]=l[i-1]+1;
        }
        ans=max(ans,l[i]);
    }
    for(int i=1;i<=n-2;i++)
    {
        if(a[i]<a[i+2]){
            ans=max(ans,l[i]+r[i+2]);
        }
    }
    printf("%d",ans);
	return 0;
}