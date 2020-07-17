#include <iostream>
#include <memory.h>
using namespace std;
int a[100005];
int b[100005];
int main(){
    int n;
    cin >> n ;
    while(n--){
        int q;
        int num = 0 ;
        cin >> q;
        int is=1;
        int least = 1;
        while(num<q){
            int h;
            cin >> h;
            if(a[h]==0){
                a[h]++;
                b[num]=h;
            }
            else{
                for(int i = least ; i <= h ; i++ ){
                    is = 0;
                    if(!a[i]){
                        is = 1;
                        b[num]=i;
                        a[i]++;
                        least=i;
                    }
                    if(is)break;
                }
                if(is == 0){
                cout << -1 << endl ;
                memset(a,0,100005);
                memset(b,0,100005);
                a[q]=0;      
                while(num<q-1){
                    int f;
                    cin >> f;
                    num++;
                } 
                break;
            }
            }
            num++;
        }
        
        if(is){
            for(int i = 0 ; i < q ; i++ ){
            cout << b[i] << " ";
            }
            cout << endl ;
        }
        memset(a,0,100005);
        memset(b,0,100005);
        
    }

    return 0;
}