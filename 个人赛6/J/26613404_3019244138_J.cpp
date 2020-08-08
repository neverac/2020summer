#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    long long  n, k;
    cin >> n >> k;
    long long max=k<<1;
    long long  day = 0;
    long long save;
    long long time = 0;
    //cout << k << max << endl ;
    for(int j = 0 ; j < n ; j++ ){
        cin >> save;
        while(save>max){
            save-=max;
            day++;
        }
        if(save>k){
            save=0;
            day++;
        }
        if(save>0) time++;
    }
    day=day+(time+1)/2;
    cout <<day<< endl ;
    return 0;
}