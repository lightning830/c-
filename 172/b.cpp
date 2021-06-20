#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    string s, t;
    cin >> s >> t;
    int n = 0;
    rep(i, s.size()){
        if(s[i] != t[i]) n++;
    }
    cout << n << endl;
    return 0;
}