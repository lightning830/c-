#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    vector<ll> still(n, -1);
    rep(i, n) cin >> a[i];
    ll now = 1;
    ll L = 0;
    ll rest = 0;
    for(ll i = 1; i <= k; i++){
        L++;
        now = a[now-1];
        // cout << "now=" << now << endl;
        if(still[now-1] > 0){
            // cout << "still" << still[now-1] << endl;
            L -= still[now-1]-1;
            // cout << "L" << L << endl;
            rest = (k - i) % L;
            break;
        }else{
            still[now-1] = i+1;
        }
    }
    for(ll i = 0; i < rest; i++){
        now = a[now-1];
        // cout << "now1=" << now << endl;
    }
    cout << now << endl;
}