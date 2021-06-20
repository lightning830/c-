#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

ll comb(int n, int a){
    ll x = 1, y = 1;
    rep(i, a){
        x *= n-i;
        y *= i+1;
    }
    return x / y;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    vector<int> same(n, 0);
    rep(i, n){
        same[a[i]-1]++;
    }
    // for(const auto& u: same){
    //     cout << u << endl;
    // }

    ll all = 0;
    rep(i, n){
        if(same[i] > 1) all += comb(same[i], 2); 
    }

    rep(i, n){
        ll ans = all - same[a[i]-1] + 1;
        cout << ans << " ";
    }


}