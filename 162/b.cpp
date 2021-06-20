#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n; cin >> n;
    ll ans = 0;
    rep(i, n){
        if((i+1)%3 != 0 && (i+1)%5 != 0) ans+=(i+1);
    }
    cout << ans << endl;
}