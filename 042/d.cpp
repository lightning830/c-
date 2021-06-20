#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

const int mod = 1000000007;
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

mint choose(int n, int a){
    mint x = 1, y = 1;
    rep(i, a){
        x *= n-i;
        y *= i+1;
    }
    return x / y;
}

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    mint ans = 0;
    mint ans1, ans2;
    for(int i = b+1; i <= w; i++){
        ans1 = choose(i-1+h-a-1, h-a-1);
        ans2 = choose(w-i-1+a, a-1);
        ans += ans1*ans2;
        // cout << i-1+h-a-1 << " " << h-a-1 << endl;
        // cout << w-i-1+a-1 << " " << a-1 << endl;
        // cout << endl;
    }
    cout << ans << endl;


    // mint ans, now1(1), now2 = choose(h+w-b-2, h-1);
    // for(int i = 0; i < h-a; i++){
    //     ans += now1*now2;
    //     now1 *= b+i;
    //     now1 = now1/(i+1);
    //     now2 = now2/(h+w-b-2-i);
    //     now2 *= h-i-1;
    // }
    // cout << ans << endl;
    return 0;

    

}