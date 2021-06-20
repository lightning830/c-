#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;
    if(n % 2){
        cout << "No" << endl;
        return 0;
    }
    n /= 2;
    rep(i, n){
        if(s[i] != s[i+n]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}