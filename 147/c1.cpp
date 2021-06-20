#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int g[15][15];

int main() {
    int n; cin >> n;
    rep(i, n)rep(j, n) g[i][j] = -1;//証言
    rep(i, n){
        int m; cin >> m;
        rep(j, m){
            int a, x;
            cin >> a >> x;
            a--;
            g[i][a] = x;
        }
    }
    int ans = 0;
    rep(i, 1<<n){//bit全探索
        vector<int> d(n);
        rep(j, n) if(i>>j & 1){//奇数
            d[j] = 1;
        }
        bool ok = true;
        rep(j, n){
            if(d[j]){//正直者の証言が狂ったらアウト
                rep(k, n){
                    if(g[j][k] == -1) continue;
                    if(g[j][k] != d[k]) ok = false;
                }
            }
        }
        if(ok) ans = max(ans, __builtin_popcount(i));
        //1の数
    }
    cout << ans << endl;

}