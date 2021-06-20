#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n, d; cin >> n >> d;
    double x[n][d];
    rep(i, n)rep(j, d) cin >> x[i][j];
    int ans = 0;
    rep(i, n-1){
        for(int j = i+1; j < n; j++){
            double dis = 0;
            rep(k, d){
                dis += (x[i][k] - x[j][k])*(x[i][k] - x[j][k]);
            }
            dis = sqrt(dis);
            if(dis == (int)dis) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}