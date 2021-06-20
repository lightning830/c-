#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n,k; cin >> n >> k;
    int h[n];
    rep(i, n) cin >> h[i];
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++){
        int minn = 1001001001;
        for(int j = 1; j <= k; j++){
            if((i-j) >= 0){//例えば10こ目では4つ戻れても、2つ目で4つは戻れない
                minn = min(minn, dp[i-j] + abs(h[i-j] - h[i]));
            }
        }

        dp[i] = minn;
    }
    // rep(i, n) cout << dp[i] << " ";
    cout << dp[n-1] << endl;
    return 0;
}