#include <bits/stdc++.h>
using namespace std;
int k,n,s,p;

int main(){
    scanf("%d%d%d%d",&k,&n,&s,&p);
    int a = ceil((double)n/s);
    int b=k*a;
    int c =ceil((double)b/p);
    printf("%d",c);
}
