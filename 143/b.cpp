#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n; cin >> n;
    int d[n];
    rep(i, n) cin >> d[i];
    int ans = 0;
    rep(i, n-1){
        for(int j = i+1; j < n; j++) ans += d[i]*d[j];
    }
    cout << ans << endl;

    return 0;
}