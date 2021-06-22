#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int h, n;
    cin >> h >> n;
    int a[n][2];
    rep(i, n){
        rep(j, 2){
            cin >> a[i][j];
        }
    }

    vector<int> dp(h+1, INF);
    dp[h] = 0;

    rep(i, n){
        for(int j = h; j > 0; j--){
            if(dp[j] == INF) continue;
            dp[max(0, j-a[i][0])] = min(dp[max(0, j-a[i][0])], dp[j] + a[i][1]);
        }
    }
    cout << dp[0] << endl;


    return 0;
}