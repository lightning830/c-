#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n+1), b(m+1);
    a[0] = 0; b[0] = 0;
    rep(i, n){
        int x; cin >> x;
        a[i+1] = a[i] + x;
    }
    rep(i, m){
        int x; cin >> x;
        b[i+1] = b[i] + x;
    }

    ll ans = 0;
    ll best = m;
    rep(i, n+1){
        if(a[i] > k) break;
        while(b[best] > k - a[i]) best--;
        ans = max(ans, i+best);
    }
    cout << ans << endl;

    return 0;
}