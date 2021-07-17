#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1e18;

map<int, ll> memo;
int main() {
    ll n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    rep(i, n){
        int A; cin >> A;
        a[i] = A;
        b[i] = A;
    } 
    sort(b.begin(), b.end());
    rep(i, n){
        memo[b[i]] = 0;
    }

    if(n <= k){
        ll add = k / n;
        k -= n * add;
        for(auto&& it:memo){
            it.second += add;
        }
    }

    for(auto&& it:memo){
        if(k > 0){
            it.second++;
            k--;
        }
    }

    rep(i, n){
        cout << memo[a[i]] << endl;
    }
    return 0;
}