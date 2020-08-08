#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

/*bool cmp(int a,int b)
{
    return a>b;
}*/

int w[100005]={0};
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int day=0;
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
        if(w[i]%k==0){
            w[i]/=k;
            day += w[i];
        }
        else{
            w[i]/=k;w[i]++;
            day += w[i];
        }
    }
    if(day%2==0){
        day /=2;
    }
    else{
        day /= 2;
        day++;
    }
    printf("%d\n",day);
    return 0;
}
