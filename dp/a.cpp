#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n; cin >> n;
    int h[n];
    rep(i, n) cin >> h[i];
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++){
        int minn = min(dp[i-2] + abs(h[i-2] - h[i]), dp[i-1] + abs(h[i-1] - h[i]));
        dp[i] = minn;
    }
    // rep(i, n) cout << dp[i] << " ";
    cout << dp[n-1] << endl;
    return 0;
}