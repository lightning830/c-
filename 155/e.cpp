#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
const int INF = 1001001001;
int dp[1000005][2];

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += '0';
    int n = s.size();
    rep(i, n+1)rep(j, 2) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i, n)rep(j, 2){
        int x = s[i] - '0';
        x += j;
        rep(a, 10){
            int ni = i+1, nj = 0;
            int b = a-x;
            if(b < 0){
                nj = 1;
                b += 10;
            }
            dp[ni][nj] = min(dp[ni][nj], dp[i][j]+a+b);
        }
    }
    int ans = dp[n][0];
    cout << ans << endl;

    // rep(i, 10)rep(j, 10){
    //     cout << i << j << " " << dp[i][j] << endl;
    // }
    return 0;
}