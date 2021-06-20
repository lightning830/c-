#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

const int INF = 1001001001;

int first(int n){
    while(n / 10 != 0){
        n /= 10;
    }
    return n;
}

int end(int n){
    return n % 10;
}

int main() {
    int n; cin >> n;
    int ans = 0;
    vector<vector<int>> c(10, vector<int>(10, 0));
    // cout << first(n) << endl;
    for(int i = 1; i <= n; i++){
        c[first(i)][end(i)]++;
    }
    rep(i, 10)rep(j, 10){
        ans += c[i][j]*c[j][i];
    }
    cout << ans << endl;

    return 0;
}