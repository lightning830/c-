#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i = 0; i < (n); i++)
using ll = long long;
using P = pair<ll, ll>;


const ll mod = 1e9+7;
class mint {
    long long x;
public:
    mint(long long x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }

    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};

vector<mint> fac(1000001); //n!(mod M)
vector<mint> ifac(1000001); //k!^{M-2} (mod M)

mint mpow(ll x, ll n){//x^n(mod M)
    mint ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x;
        x = x*x % mod;
        n = n >> 1;
    }
    return ans;
}

mint comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    mint tmp = ifac[a-b]* ifac[b];
    return tmp * fac[a];
}

int main() {
    ll x, y;
    cin >> x >> y;
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<1000000; i++){
        fac[i+1] = fac[i]*(i+1); // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, mod-2); // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
    ll dx[] = {1, 2};
    ll dy[] = {2, 1};
    queue<P> q;
    q.push(P(0,0));
    vector<vector<ll>> dist(1000000, vector<ll>(1000000, 0));
    while(!q.empty()){
        P tmp = q.front();
        q.pop();
        auto update = [&](ll i, ll j, ll num1){
            q.push(P(i, j));
            dist[i][j] = num1; 
            // cout << i << j << endl;
        };
        rep(i, 2){
            ll next_x = tmp.first + dx[i];
            ll next_y = tmp.second + dy[i];
            if(next_x > x || next_y > y) continue;
            update(next_x, next_y, dist[tmp.first][tmp.second]+(dx[i]==1? 1: 0));

            
        }

    }

    // rep(i, dist.size()){
    //     rep(j, dist[0].size()){
    //         cout << dist[j][i];
    //     }
    //     cout << endl;
    // }

    if(dist[x][y] == 0){
        cout << 0 << endl;
        return 0;
    }
    // cout << dist[x][y]+(x-dist[x][y])/2 << " " << dist[x][y] << endl;
    cout << comb(dist[x][y]+(x-dist[x][y])/2, dist[x][y]) << endl;

    return 0;
}