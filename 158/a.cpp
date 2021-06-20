#include<iostream>
#include<string.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
int main(){
    char s[3];
    rep(i, 3){
        cin >> s[i];
    }    
    if(strncmp(&s[0], &s[1],1)==0 && strncmp(&s[1], &s[2],1) ==0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}