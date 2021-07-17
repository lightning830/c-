#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)
using P = pair<ll, ll>;
map<string, ll> memo;
const int INF = 1001001001;
const ll LINF = 1e18;

int main() {
    ll n; cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, n){
        if(a[i] >= 10){
            ans += a[i]-10;
        }
    }
    cout << ans << endl;

    return 0;
}