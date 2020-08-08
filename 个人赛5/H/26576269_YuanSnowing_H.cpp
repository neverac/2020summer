#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5; 
bool number[maxn+5];
void isprime(){
    int prime[maxn+5];
    int i,j,c=0;
    memset(number,true,sizeof(number));
    for(i=2;i<=maxn;i++){
        if(number[i])
            prime[c++]=i;
        for(j=0;j<c&&prime[j]*i<=maxn;j++){
            number[prime[j]*i]=false;
            if(i%prime[j]==0) break;//保证每个合数只会被它的最小质因数筛去，因此每个数只会被标记一次
        }
    }
}
int n;
int main(){
	isprime();
    cin >> n;
    int tmp=0;
    while(!number[n+tmp]) tmp++;
    cout << tmp+n<<endl;
    for(int i=1;i < n; ++ i){
    	cout << i <<" "<< i+1 << endl;
    }
    cout << n <<" "<< 1 << endl;
    for(int i=1;i<=tmp; ++ i){
    	cout << i <<" "<< i+n/2<<endl;
    }
    return 0;
} 