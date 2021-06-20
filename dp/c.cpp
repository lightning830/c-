#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n; cin >> n;
    int a[n], b[n], c[n];
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    int dp[n][3];
    rep(i, n)rep(j, 3) dp[i][j] = 0;
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    rep(i, n-1){
        dp[i+1][0] = max(dp[i][1]+a[i+1], dp[i][2]+a[i+1]);
        dp[i+1][1] = max(dp[i][0]+b[i+1], dp[i][2]+b[i+1]);
        dp[i+1][2] = max(dp[i][1]+c[i+1], dp[i][0]+c[i+1]);
        // cout << dp[i+1][0] << " " << dp[i+1][1] << " " << dp[i+1][2] << endl;
    }
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;

    return 0;
}