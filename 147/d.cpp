#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

const int mod = 1e9+7;
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

int main() {
    int n; cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];

    vector<ll> d(60, 0);
    mint ans = 0;
    rep(i, 60){
        ll x = 0;
        ll y = 0;
        rep(j, n){
            if(a[j]>>i & 1) y++;
            else x++;
        }
        d[i] = x * y; //0xor1のときのみ1になるから0の数*1の数のパターンを数えればよい
        //d[i]=下からiビット目にxor=1がなん回登場するか
    }
    
    rep(i, 60){
        mint tmp = d[i];
        rep(j, i){
            tmp *= 2;//d[i]をそれぞれ10進数に直して足す        }
        ans += tmp;
    }
    cout << ans << endl;


}