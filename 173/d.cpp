#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    vector<ll> b(n);
    b[0] = a[0];
    ll ma = a[0];
    ll sum = a[0];
    for(int i = 1; i < n; i++){
        
    }

    return 0;
}