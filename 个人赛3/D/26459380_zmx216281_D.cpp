#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

int a[200010],b[200010];
bool isPrime(int x){
	bool flag=true;;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			flag=false;
		}
	}
	return flag;
}

int main(){
    int n;
    int cnt1=0,cnt2=0;
    int qianzhui = 0;
	cin>>n;
	for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
		if(a[i]==1)cnt1++;
        else cnt2++;
	}
	if(cnt2>0){
        qianzhui+=2;
        b[0]=2;
        cnt2--;
    }
    else{
        qianzhui+=1;
        b[0]=1;
        cnt1--;
    }
    for(int i=1;i<n;i++){
        if((cnt1!=0&&isPrime(qianzhui+1))||(cnt2==0)){
            b[i]=1;
            qianzhui++;
            cnt1--;
        }
        else{
            b[i]=2;
            qianzhui+=2;
            cnt2--;
        }
    }
    for(int i=0;i<n;i++){
        cout << b[i] << " ";
    }
	return 0;
}