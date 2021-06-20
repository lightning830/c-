#include<iostream>
#include<list>
#include<string>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    list<char> S;
    string s;
    cin >> s;
    const char* cstr = s.c_str();
    while(*cstr != '\0'){
        S.push_back(*cstr);
        cstr++;
    }

    int q;
    cin >> q;
    int t[q], f[q];
    char c[q];
    bool start = true;
    rep(i, q){
        cin >> t[i];
        if(t[i] == 2){
            cin >> f[i] >> c[i];
            if(f[i] == 1){
                if(start) S.push_front(c[i]);
                else S.push_back(c[i]);
            }else{
                if(!start) S.push_front(c[i]);
                else S.push_back(c[i]);
            }
        }else{
            // cout << "reverse" << endl;
            start = !start;
        }
        // for(auto&& n: S){
        //     cout << n;
        // }cout << endl;
    }
    if(!start) S.reverse();

    for(auto&& n: S){
        cout << n;
    }






    // rep(i, q){
    //     cin >> t[i];
    //     if(t[i] == 2){
    //         cin >> f[i] >> c[i];
    //         if(f[i] == 1){
    //             S.push_front(c[i]);
    //         }else{
    //             S.push_back(c[i]);
    //         }
    //     }else{
    //         // cout << "reverse" << endl;
    //         S.reverse();
    //     }
    //     // for(auto&& n: S){
    //     //     cout << n;
    //     // }cout << endl;
    // }

    // for(auto&& n: S){
    //     cout << n;
    // }
}