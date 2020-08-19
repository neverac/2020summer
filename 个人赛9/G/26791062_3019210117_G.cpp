#include <iostream>
#include <set>
using namespace std;
set<long long int>A[3];
long long int p[200005],ans;
void print(){
    for(int i=0;i<2;i++){
        set<long long int>::iterator it;
        for(it=A[i].begin();it!=A[i].end();it++){
            printf("%lld ",*it);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
   // freopen("in.txt","r",stdin);
    for(int i=0;i<3;i++){
        A[i].clear();
    }
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",p+i);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        A[x-1].insert(p[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        A[x-1].insert(p[i]);
    }
    //print();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(A[x-1].size()<=0){
            printf("-1 ");
        }else{
            ans=*A[x-1].begin();
            printf("%lld ",ans);
            for(int i=0;i<3;i++){
                A[i].erase(ans);
            }
        }
    }
    return 0;
}