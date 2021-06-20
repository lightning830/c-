#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    string s; cin >> s;
    rep(i, s.size()-1){
        if(s[i] == s[i+1]){
            cout << "Bad" << endl;
            return 0;
        }
    }
    cout << "Good" << endl;

    return 0;
}