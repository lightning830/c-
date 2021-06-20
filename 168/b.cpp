#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int k;
    string s;
    cin >> k >> s;
    if(s.size() <= k){
        cout << s << endl;
        return 0;
    }
    rep(i, k){
        cout << s[i];
    }
    cout << "...";

    return 0;
}