#include <iostream>
#include <algorithm>
using namespace std;
struct que{
    int id,k,pos,ans;
}quearr[105];
bool comp11(que a,que b){
    return a.k<b.k;
}
bool comp12(que a,que b){
    return a.id<b.id;
}
struct seqa{
    int val,id;
}arra[105],arrlis[105];
bool comp21(seqa a,seqa b){
    if(a.val==b.val){
        return a.id<b.id;
    }
    return a.val>b.val;
}
bool comp22(seqa a,seqa b){
    return a.id<b.id;
}
int len=0;
int main(){
   // freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arra[i].val);
        arra[i].id=i;
    }
    sort(arra,arra+n,comp21);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&quearr[i].k,&quearr[i].pos);
        quearr[i].id=i;
    }
    sort(quearr,quearr+m,comp11);
    for(int i=0;i<m;i++){
        for(;len<quearr[i].k;len++){
            arrlis[len]=arra[len];
        }
        sort(arrlis,arrlis+len,comp22);
        quearr[i].ans=arrlis[quearr[i].pos-1].val;
    }
    sort(quearr,quearr+m,comp12);
    for(int i=0;i<m;i++){
        printf("%d\n",quearr[i].ans);
    }
    return 0;
}