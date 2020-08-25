#include <iostream>
using namespace std;
int main(){
	int T,a[10],totcnt;
    cin>>T;
	while(T--){
		totcnt=0;
		for(int i=0;i<=9;i++){
            cin>>a[i];
            totcnt+=a[i];
		}
		if(totcnt==a[0]){
            printf("0\n");
		}else{
            int x=-1,y=-1,flag=0;
            for(int i=0;i<=9;i++){
                for(int j=0;j<=i;j++){
                    if(i==j&&a[i]>1){
                        if((i*10+j)%4==0){
                            x=i;
                            y=j;
                            flag=1;
                            break;
                        }else if((j*10+i)%4==0){
                            x=j;
                            y=i;
                            flag=1;
                            break;
                        }
                    }else if(i!=j&&a[i]*a[j]>0){
                        if((i*10+j)%4==0){
                            x=i;
                            y=j;
                            flag=1;
                            break;
                        }else if((j*10+i)%4==0){
                            x=j;
                            y=i;
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag){
                    break;
                }
            }
            if(flag){
                a[x]--;
                a[y]--;
                for(int i=9;i>=0;i--){
                    while(a[i]--){
                        printf("%d",i);
                    }
                }
                printf("%d%d\n",x,y);
            }else if(a[8]){
                printf("8\n");
            }else if(a[4]){
                printf("4\n");
            }else if(a[0]){
                printf("0\n");
            }else{
                printf("-1\n");
            }
        }
	}
	return 0;
 } 