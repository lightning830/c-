#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int n,w;
vector<P> item;
vector<vector<int>> dp;

int rec(int i, int j){
    int res;
    if(dp[i][j] >= 0) return dp[i][j];
    if(i == n) res = 0;
    else if(j - item[i].first < 0) res = rec(i+1, j);
    else{
        res = max(rec(i+1, j), rec(i+1, j-item[i].first) + item[i].second);
    }
    dp[i][j] = res;
    return res;
}

int main() {
    cin >> n >> w;
    dp.resize(n+1, vector<int>(w+1));
    rep(i, n+1)rep(j, w+1) dp[i][j] = -1;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        item.push_back(P(a,b));
    } 
    cout << rec(0, w) << endl;

}