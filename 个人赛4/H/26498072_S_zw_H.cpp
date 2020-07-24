#include<stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#define N 10005
#define INF 0x3f3f3f3f
using namespace std;

map<string,vector<string>> Map;
int n;

int issuf(string a,string b){
    int i = a.size()-1,j = b.size()-1;
    while (i >= 0 && j >= 0)
    {
        if(a[i] == b[j]){
            i--;j--;
        }else{
            break;
        }
    }
    if(i == -1){
        return 1;
    }
    if(j == -1){
        return -1;
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int m;
        cin>>m;
        if(Map.find(s) == Map.end()){
            vector<string>tmp;
            Map[s] = tmp;
        }
        for(int j=0;j<m;j++){
            string num;
            cin>>num;
            vector<string> tmp = Map.at(s);
            int flag = 0;
            for(int k=0;k<tmp.size();k++){
                switch (issuf(num,tmp[k]))
                {
                    case 1:
                        flag = 1;
                        break;
                    case -1 :
                        tmp[k] = num;
                        flag = -1;
                        break;
                    default:
                        break;
                }
            }
            if(flag == 0){
                tmp.push_back(num);
            } 
            Map[s] = tmp;
        }
    }
    printf("%d\n",Map.size());
    map<string,vector<string>>::iterator itor;
    for(itor = Map.begin();itor!=Map.end();itor++){
        vector<string> tmp = itor->second;
        cout<<itor->first<<" "<<tmp.size();
        for(int j=0;j<tmp.size();j++){
            cout<<" "<<tmp[j];
        }
        cout<<endl;
    }
    
    return 0;
}
 