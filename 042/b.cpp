#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n, l;
    cin >> n >> l;
    string s[n];
    rep(i, n) cin >> s[i];
    while(1){
        bool check = false;
        rep(i, n-1){
            string a = s[i];
            string b = s[i+1];
            if(a+b > b+a){
                s[i] = b;
                s[i+1] = a;
                check = true;
            }
        }
        if(!check)break;
    }
    rep(i, n) cout << s[i];

}