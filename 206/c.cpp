#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

map<ll, ll> memo;
int main() {
    ll N;
    cin >> N;

    rep(i, N){
        ll a;
        cin >> a;
        memo[a]++;
    }

    ll sum = (N*(N-1))/2;
    for(auto& x:memo){
        if(x.second > 1){
            sum -= (x.second*(x.second-1))/2;
        }
    }

    cout << sum << endl;

    return 0;
}