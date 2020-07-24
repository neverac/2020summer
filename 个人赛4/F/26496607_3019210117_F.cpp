#include <iostream>
using namespace std;
int main(){
    int k,n,s,p,perpa,totpa;
    scanf("%d%d%d%d",&k,&n,&s,&p);
    perpa=n/s+(n%s>0);
    totpa=perpa*k;
    printf("%d",totpa/p+(totpa%p>0));
    return 0;
}