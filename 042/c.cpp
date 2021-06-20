#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;


int main() {
    int n;
    int k;
    cin >> n >> k;
    int d[k];
    rep(i, k) cin >> d[i];

    while(1){
        string s = to_string(n);
        bool check = true;
        rep(i, s.size()){
            bool acheck = true;
            rep(j, k){
                if(s[i]-'0' == d[j]){
                    acheck = false;
                } 
            }
            if(acheck == false){
                check = false;
                break;
            }
        }
        if(check) break;
        n++;
    }
    cout << n << endl;



    // rep(i, n.size()){
    //     bool kirai = [&](int a){
    //         bool check = true;
    //         rep(j, k){
    //             if(s[i]-'0' == d[j]){
    //                 check = false;
    //             } 
    //         }
    //         return check;
    //     }

    //     if(kirai(s[i]-'0')){
    //         rep(s[i]-'0', k){
    //             if(kirai(s[i]-'0'+1))
    //         }
    //     }
    // }

}