#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    int c[n];
    int a[n][m];
    rep(i, n){
        cin >> c[i];
        rep(j, m){
            cin >> a[i][j];
        }
    }
    ll INF = 1001001001;
    ll ans = INF;
    rep(i, 1<<n){//bit全探索
        ll sum = 0;
        vector<int> d(m, 0);
        rep(j, n){
            if(i>>j & 1){//奇数
                rep(k, m){
                    d[k] += a[j][k];
                }
                sum += c[j];
            }
        } 
        bool check = true;
        rep(j, m){
            if(d[j] < x) check = false;
        }
        if(check) ans = min(ans, sum);
        
    }
    cout << (ans == INF? -1: ans) << endl;
}