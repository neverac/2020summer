#include<iostream>
#include<cstdio>
#include<cmath>
int a[365],S[365];
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        S[i]=S[i-1]+a[i];
    }
    if(n==1)cout << 360 << endl;
    else{
        int mmin = 1e9;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int temp = S[j]-S[i];
			    if( temp == 180 ){
				    cout << '0' << endl;
				    return 0;
			    }
			    else{
			   	    mmin = min( mmin , abs(temp-180) );
			    }
            }
        }
        cout << mmin*2 << endl;
    }
}