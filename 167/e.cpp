#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

const ll mod = 998244353;
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

vector<mint> fac(300001); //n!(mod M)
vector<mint> ifac(300001); //k!^{M-2} (mod M)

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
    ll n, m, k;
    cin >> n >> m >> k;

    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1); // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, mod-2); // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
    mint ans = 0;
    mint m2 = m;
    for(int i = 0; i <= k; i++){
        ans += m2 * (m2-1).pow(n-i-1) * comb(n-1, i);
    }
    cout << ans << endl;

}