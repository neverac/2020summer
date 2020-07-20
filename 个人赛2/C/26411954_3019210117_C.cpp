#include<iostream>
#include<cstring>
using namespace std;
long long int max(long long int a,long long int b){
    if(a>b){
        return a;
    }
    return b;
}
int main(){
    char a[205];
    int t,n;
	//freopen("in.txt","r",stdin); 
    long long int max1,temp1,temp2,aa,b,c,d,e;
    while(scanf("%d",&t)==1){
        for(int ii=1;ii<=t;ii++){
            scanf("%s",a);
            max1=-1000000000000000000;
            n=strlen(a);
            for(int i=2;i<n-2;i++){
                aa=a[0]-'0';
                b=0;
                for(int j=1;j<i;j++){
                    b=b*10+(a[j]-'0');
                }
                temp1=aa+b;
                aa=0;
                for(int j=0;j<i-1;j++){
                    aa=aa*10+(a[j]-'0');
                }
                b=a[i-1]-'0';
                temp2=aa+b;
                c=a[i]-'0';
                d=a[i+1]-'0';
                e=0;
                for(int j=i+2;j<n;j++){
                    e=e*10+(a[j]-'0');	
                }
                max1=max(max1,max(temp1,temp2)-c*d/e);
            
            }
            printf("Case #%d: %lld\n",ii,max1);
        }
    }
    return 0;
}