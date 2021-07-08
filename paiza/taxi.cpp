#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1e18;

int main() {
    ll n, x;
    cin >> n >> x;
    ll a[n], b[n], c[n], d[n];
    rep(i, n){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    
    ll MIN = LINF;
    ll MAX = 0;

    rep(i, n){
        if(a[i] > x){
            MIN = min(MIN, b[i]);
            MAX = max(MAX, b[i]);
            continue;
        }
        ll q = (x-a[i]) / c[i];
        ll add_pay = d[i] * (q+1);
        ll sum = add_pay + b[i];
        // cout << i << ":" << q << " " << add_pay << " " << sum << endl;
        MIN = min(MIN, sum);
        MAX = max(MAX, sum);
    }

    cout << MIN << " " << MAX << endl;
    return 0;
}