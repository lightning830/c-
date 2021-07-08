#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1e18;

int main() {
    ll n, K;
    cin >> n >> K;
    ll ans = 0;

    if(n>K){
        cout << 0 << endl;
        return 0;
    }

    rep(i, 1<<2*n){
        int num = 0;
        rep(j, 2*n){
            if(i>>j & 1){
                num++;
            }
        }
        if(num != n) continue;
        // cout << bitset<6>(i) << " " << bitset<6>(~i) << endl;
        ll a = i, b = ~i;
        int dif = 0;
        rep(j, 2*n){
            if(a>>j & 1){
                rep(k, 2*n){
                    if(b>>k & 1){
                        b &= ~(1<<k);//kビット目を0にする
                        // b ^= (1<<N); //kビット目を反転する
                        // cout << "next " << bitset<6>(b) << endl;
                        dif += abs(k-j);
                        break;
                    }
                }
            }
        }
        if(dif <= K) ans++;
    }
    cout << ans << endl;


    return 0;
}