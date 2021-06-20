#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;


ll ketadp(string s){
    int n = s.size();
    ll dp[n+1][2][2];
    rep(i, n+1)rep(j, 2)rep(k, 2) dp[i][j][k] = 0;
    dp[0][0][0] = 1;

    rep(i ,n)rep(j, 2)rep(k, 2){
        for(int x = 0; x <= (!j?s[i]-'0':9); x++){
            dp[i+1][j || x < s[i]-'0'][k || x==4 || x==9]
                += dp[i][j][k];
        }
    }
    return dp[n][0][1] + dp[n][1][1];
}

int main() {
    ll a,b;
    cin >> a >> b;
    a--;
    string a1 = to_string(a), b1 = to_string(b);
    // cout << ketadp(b1) << endl << ketadp(a1) << endl;
    cout << ketadp(b1) - ketadp(a1) << endl;

}