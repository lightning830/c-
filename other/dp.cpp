#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;

//s以下の整数で3が含まれる整数はいくつあるか

int main() {
    string s;
    cin >> s;
    int n = s.size();
    // cout << n << endl;
    // s += '0';
    // cout << s << endl;
    int dp[n+1][2][2];
    //dp[i][j][k] 
    //i桁目までを確定したときその数はsより小さい(j=1)
    //その数の中に3を含む(k=1),の数がいくつあるか

    rep(i, n+1)rep(j, 2)rep(k, 2) dp[i][j][k] = 0;
    dp[0][0][0] = 1;

    rep(i, n){//先頭の桁から dp[n][][]まで行くから問題ない
        rep(j, 2){//未満とそうじゃないときと
            rep(k, 2){//3があるかどうかで繰り返していく
                if(j){
                    rep(x, 10){
                        dp[i+1][1][k || x == 3] += dp[i][j][k];
                        // cout << "i=" << i << "j=" << j << "k=" << k << endl;
                        // cout << "+=" << dp[i][j][k] << endl;
                        // cout << "dp" << i+1 << "," << 1 << "," << (k || x == 3) << "=" << dp[i+1][1][k || x == 3] << endl;
                    }
                }else{
                    for(int x = 0; x <= s[i]-'0'; x++){
                        dp[i+1][x < s[i]-'0'][k || x == 3] +=
                            dp[i][j][k];
                        // cout << "i=" << i << "j=" << j << "k=" << k << endl;
                        // cout << "+=" << dp[i][j][k] << endl;
                        // cout << "dp" << i+1 << "," << (x < s[i]-'0') << "," << (k || x == 3) << "=" << dp[i+1][x < s[i]-'0'][k || x == 3] << endl;
                        
                    }
                }
            }
        }
    }
    cout << dp[n][0][1] + dp[n][1][1] << endl;
    // rep(i, n+1)rep(j, 2)rep(k, 2){
    //     cout << dp[i][j][k] << " i=" << i << "j=" << j << "k=" << k << endl;
    // }
    return 0;
}