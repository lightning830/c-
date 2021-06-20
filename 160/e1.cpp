#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;


int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    vector<int> d;
    rep(i, x) d.push_back(p[i]);
    rep(i, y) d.push_back(q[i]);
    rep(i, c) d.push_back(r[i]);
    sort(d.rbegin(), d.rend());
    ll ans = 0;
    rep(i, x+y) ans += d[i];
    cout << ans << endl;
    return 0;
}