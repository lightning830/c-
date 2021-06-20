#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int n = 0;
    // cout << s[0] << " " << s[s.size()-1] << endl;
    rep(i, s.size()/2){
        // cout << s[i] << " " << s[s.size()-1-i] << endl;
        if(s[i] != s[s.size()-1-i]) n++;
    }
    cout << n << endl;
}