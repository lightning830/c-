#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n; cin >> n;
    int a[n];
    map<int, int> h;
    rep(i, n){
        cin >> a[i];
        h[i-a[i]]++;
    } 
    ll ans = 0;
    rep(i, n){
        ans += h[i+a[i]];
    }
    cout << ans << endl;

    return 0;
}