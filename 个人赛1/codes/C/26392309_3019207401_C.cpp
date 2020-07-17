#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n,value[100001],a[100001],ans[100001],t,pos;
void answer(){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>value[i];
            a[i]=0;
        }
        int maxx=value[1];
        pos=1;
        ans[1]=value[1];
        a[value[1]]=1;
        for(int i=2;i<=n;i++){
            if(value[i]<maxx){
                cout<<-1<<endl;
                return;
            }
             if(value[i]>maxx){
                ans[i]=value[i];
            }
            else {
                while(a[pos]) {
                    pos++;
                }
                if(pos>maxx) {
                    cout<<-1<<endl;
                    return ;
                }
			    ans[i]=pos;
		    }
		a[ans[i]]=1;
		maxx=max(maxx,ans[i]);
	}

      for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
      }
      cout<<endl;
    }

int main()
{
    cin>>t;
    for(int coun=0;coun<t;coun++){
            answer();
    }
    return 0;
}
