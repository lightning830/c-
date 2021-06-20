#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
    } 
    rep(i, n){
        if(a[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    } 
    // sort(a.begin(), a.end());
    ll ans = 1;
    ll ans1 = 1000000000000000000;
    rep(i, n){
        ans *= a[i];
        ans1 /= a[i];
    } 
    if(ans1 < 1){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}