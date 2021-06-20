#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    const char* cstr = s.c_str();
    bool check = false;
    while(*cstr != '\0'){
        if(*cstr == 'h' && *(cstr+1) == 'i'){
            check = true;
        }else{
            check = false;
        }
        cstr += 2;
    }
    cout << (check? "Yes": "No") << endl;
}