#include<iostream>
using namespace std;
int n,m,h,r[105],c[105],x;
int main(){
    //freopen("in.txt","r",stdin);
    cin>>n>>m>>h;
    for(int i=0;i<m;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            if(x==0){
                cout<<x;
            }else{
                if(r[i]<c[j]){
                    cout<<r[i];
                }else{
                    cout<<c[j];
                }
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}