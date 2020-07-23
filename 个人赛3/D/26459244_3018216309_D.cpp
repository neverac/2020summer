#include <bits/stdc++.h>
using namespace std;
int n,cnt1=0,cnt2=0;

int isprime(int x){
	int flag=1;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			flag=0;
		}
	}
	return flag;
}

int main(){
    scanf("%d",&n);
    int tem;
    for(int i=0;i<n;++i){
        scanf("%d",&tem);
        if(tem==1) cnt1++;
        else cnt2++;
    }
    int sum=0;
    if(cnt2!=0){
        sum+=2;
        printf("2 ");
        cnt2--;
    }
    else{
        sum+=1;
        printf("1 ");
        cnt1--;
    }
    for(int i=1;i<n;++i){

        if((cnt1!=0&&isprime(sum+1))||(cnt2==0&&cnt1!=0)){
            sum+=1;
            cnt1--;
            printf("1 ");
        }
        else{
            sum+=2;
            cnt2--;
            printf("2 ");
        }
    }

}
