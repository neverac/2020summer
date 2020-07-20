#include <iostream>
#include <cstring>
unsigned int ans[65537];
char check[65537];
int main(){
   // freopen("in.txt","r",stdin);
	unsigned int A,B,C,S,count=0,i=0,base=0,a,j=0;
	while(scanf("%d ",&A)&&A!=0){
		scanf("%d %d %d",&B,&C,&S);
		memset(check,0,sizeof(check));
		count=0;
		while(!check[S]){
			check[S]=1;
			ans[count++]=S;
			S=(A*S+B)%C;
		}
		base=1<<15;
		for(i=0;i<16;i++){
			a=ans[0]&base;
			for(j=1;j<count;j++){
				if(a!=(ans[j]&base)){
					break;
				}
			}
			if(j!=count){
				printf("?");
			}
			else{
                if(a==0){
				    printf("0");
                }else{
				    printf("1");
                }
			}
			base>>=1;
		}
		printf("\n");
	}
    return 0;
}