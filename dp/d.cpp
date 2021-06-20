#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n, w; cin >> n >> w;
    int w[n], v[n];
    rep(i, n) cin >> w[i] >> v[i];
    int dp[110][1010];//i番目まで決めたときの価値j以上となる最小の重さ
    rep(i, 1010) dp[0][i] = 0;




    return 0;
}