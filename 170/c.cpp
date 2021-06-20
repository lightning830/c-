#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int x, n; cin >> x >> n;
    int p[n];
    rep(i, n) cin >> p[i];
    int left = x, right = x;
    if(n == 0){
        cout << x << endl;
        return 0;
    }
    bool frag1 = true;
    rep(i, n){
        if(p[i] == x) frag1 = false;
    }
    if(frag1){
        cout << x << endl;
        return 0;
    }
    while(1){
        left--;
        bool frag = true;
        rep(i,n){
            if(left == p[i]) frag = false;
        }
        if(frag){
            // cout << "now" <<endl;
            cout << left << endl;
            return 0;
        }
        right++;
        frag = true;
        rep(i,n){
            if(right == p[i]) frag = false;
        }
        if(frag){
            cout << right << endl;
            return 0;
        }

    }

    return 0;
}