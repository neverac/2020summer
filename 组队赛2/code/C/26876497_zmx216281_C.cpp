#include<iostream>
#include<cstdio>
using namespace std;
int a[60];
int n;
int main(){
    cin >> n;
    bool flag = true;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if (i!=j&&j!=k&&i!=k&&(a[i]-a[j])%a[k])
                    flag = false;
            }
        }
    }
    if(flag)cout << "yes" << endl;
    else cout << "no" << endl;
}