#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
inline int readint(){
    int ret = 0;
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
inline ll readll(){
    ll ret = 0;
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
int person_cnt = 0;
struct Person{
    string name;
    int number_cnt = 0;
    string number[210];
    bool is_delete[210];
}person[21];
int ans[21];
int main(){
    int n = readint();
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; i++){
        memset(person[i].is_delete, 0, sizeof(person[i].is_delete));
        string name;
        cin >> name;
        int id;
        bool exist = false;
        for(int j = 1; j <= person_cnt; j++){
            if(name.compare(person[j].name) == 0){
                exist = true;
                id = j;
                break;
            }
        }
        if(!exist){
            ++person_cnt;
            id = person_cnt;
        }
        person[id].name = name;
        int number_cnt = readint();
        for(int j = 1; j <= number_cnt; j++){
            ++person[id].number_cnt;
            cin >> person[id].number[person[id].number_cnt];
        }
    }
    for(int i = 1; i <= person_cnt; i++){
        sort(person[i].number + 1, person[i].number + person[i].number_cnt + 1);
        for(int j = 1; j <= person[i].number_cnt - 1; j++){
            if(person[i].number[j].compare(person[i].number[j + 1]) == 0){
                person[i].is_delete[j + 1] = true;
            }
        }
    }
    for(int i = 1; i <= person_cnt; i++){
        for(int j = 1; j <= person[i].number_cnt; j++)
        for(int k = j + 1; k <= person[i].number_cnt; k++){
            if(person[i].is_delete[j] || person[i].is_delete[k])continue;
            int len1 = person[i].number[j].length();
            int len2 = person[i].number[k].length();
            if(len1 == len2)continue;
            else if(len1 > len2){
                if(person[i].number[j].compare(len1 - len2, len2, person[i].number[k]) == 0){
                    person[i].is_delete[k] = true;
                }
            }
            else if(len2 > len1){
                if(person[i].number[k].compare(len2 - len1, len1, person[i].number[j]) == 0){
                    person[i].is_delete[j] = true;
                }
            }
        }
    }
    for(int i = 1; i <= person_cnt; i++){
        for(int j = 1; j <= person[i].number_cnt; j++){
            if(person[i].is_delete[j] == false){
                ++ans[i];
            }
        }
    }
    printf("%d\n", person_cnt);
    for(int i = 1; i <= person_cnt; i++){
        cout << person[i].name << ' ' << ans[i] << ' ';
        for(int j = 1; j <= person[i].number_cnt; j++)
        if(person[i].is_delete[j] == false){
            cout << person[i].number[j] << ' ';
        }
        cout << endl;
    }
    return 0;
}