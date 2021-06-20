#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    string n; cin >> n;
    bool check = false;
    rep(i, n.size()){
        if(n[i]=='7') check = true;
    }
    cout << (check? "Yes": "No") << endl;
}