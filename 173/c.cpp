#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int h, w, k; cin >> h >> w >> k;
    char c0[h][w];
    char c[h][w];
    rep(i, h)rep(j, w){
        cin >> c0[i][j];
        c[i][j] = c0[i][j];
    } 
    int ans = 0;
    rep(i, 1<<h){//bit全探索
        rep(j, 1<<w){
            rep(m, h){
                if(i>>m & 1){
                    rep(a, w){
                        if(c[m][a] == '#') c[m][a] = '.';
                    }
                }
            }
            rep(l, w){
                if(j>>l & 1){
                    rep(a, h){
                        if(c[a][l] == '#') c[a][l] = '.';
                    }
                }
            }
            int sum = 0;
            rep(i, h)rep(j, w){
                if(c[i][j] == '#') sum++;
            }
            if(sum == k){
                ans++;
            }

            rep(a, h)rep(b, w) c[a][b] = c0[a][b];
        }
    }
    cout << ans << endl;


    return 0;
}