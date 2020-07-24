#include <iostream>

using namespace std;

int main()
{
    int c,n,a,b,i = 1;
    cin>>c;
    while(c--){
        cin>>n>>a>>b;
        int temp = (a>b)?b:a;
       while(a%temp!=0||b%temp!=0)
       {
           temp--;
     	}
     	//cout<<"temp"<<temp<<endl;
     	//cout<<"n"<<n<<endl;
        int res = n/temp;
        //cout<<"res"<<res<<endl;
        cout<<"Case #"<<i<<": ";
        if(res%2 == 0){
            cout<<"Iaka"<<endl;
        }else{
            cout<<"Yuwgna"<<endl;
        }
        i++;
    }
    return 0;
}
