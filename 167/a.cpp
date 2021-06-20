#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    string s, t;
    cin >> s >> t;
    bool check = true;
    rep(i, s.size()){
        if(s[i] != t[i]) check = false;
    }
    cout << (check? "Yes": "No") << endl;
}