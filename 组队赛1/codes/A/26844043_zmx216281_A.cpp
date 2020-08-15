#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
int main(){
    
    string s1,s2;
    int n;
    cin >> n;
    cin >> s1;
    while(n--){
        bool flag = false;
        cin >> s2;
        if(s2==s1){
            flag = true;
        }
        
        else{
            int i=0,j=0;
            while(i<s1.length()&&j<s2.length()){
            if(s1[i]!=s2[j]||(s1[i]==s2[j]&&s1[i]>='0'&&s1[i]<='9')){
                if((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z')){
                    if(s2[i]>s1[i]){
                        flag=true;
                    }
                    else{
                        flag=false;
                    }
                    break;
                }
                else if(s1[i]>='0'&&s1[i]<='9'){
                    if(s2[i]>='0'&&s2[i]<='9'){
                        int a=0,b=0;
                        for(;i<s1.length();i++){
                            if(s1[i]>='0'&&s1[i]<='9'){
                                a=a*10+s1[i]-'0';
                            }
                            else{
                                break;
                            }        
                        }
                        for(;j<s2.length();j++){
                            if(s2[j]>='0'&&s2[j]<='9'){
                                b=b*10+s2[j]-'0';
                            }
                            else{
                                break;
                            }        
                        }
                        i--,j--;
                        if(a<b){
                            flag=true;
                            break;
                        }
                        else if(a>b){
                            flag=false;
                            break;
                        }
                    }
                    else{
                        flag = true;
                        break;
                    }
                }
            }
            if(i==s1.length()-1&&j<s2.length()){
                flag=true;
            }
            i++,j++;
        }
        }

        if(flag)cout << '+' << endl;
        else{
            cout << '-'<<endl;
        }
    }
}