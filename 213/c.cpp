#pragma region Macros
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1001001001;
const ll LINF = 1e18;
const ll MOD = 1e9+7;

#define rep(i,n) for(ll i = 0; i < (n); i++)
#define repd(i,n) for(ll i = n-1; i >= 0; i--)
#define FOR(i,a,b) for(ll i = a; i <= ll(b); i++)
#define FORD(i,a,b) for(ll i = a; i >= ll(b); i--)
#define FORA(i,I) for(const auto& i:I)

#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 
#define pb push_back
#define mp make_pair

#define F first
#define S second
#define V vector
#define P pair<ll, ll>
#define M map<ll, ll>
//繰り上げ、繰り下げ
ll myceil(ll a,ll b){return (a+(b-1))/b;}
ll myfloor(ll a,ll b){return a/b;}
//最大値、最小値を更新
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a, b);}

struct UnionFind
{
    vector<ll> d;
    UnionFind(ll n = 0): d(n, -1){}
    ll find(ll x){
        if(d[x] < 0) return x;
        return d[x] = find(d[x]);
    }

    bool unite(ll x, ll y){
        x = find(x); y = find(y);
        if(x == y) return false;
        if(d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(ll x, ll y){return find(x) == find(y);}
    ll size(ll x){return -d[find(x)];}
};

class mll {
    long long x;
public:
    mll(long long x=0) : x((x%MOD+MOD)%MOD) {}
    mll operator-() const { 
      return mll(-x);
    }
    mll& operator+=(const mll& a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mll& operator-=(const mll& a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mll& operator*=(const  mll& a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mll operator+(const mll& a) const {
        mll res(*this);
        return res+=a;
    }
    mll operator-(const mll& a) const {
        mll res(*this);
        return res-=a;
    }
    mll operator*(const mll& a) const {
        mll res(*this);
        return res*=a;
    }
    mll pow(ll t) const {
        if (!t) return 1;
        mll a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime MOD
    mll inv() const {
        return pow(MOD-2);
    }
    mll& operator/=(const mll& a) {
        return (*this) *= a.inv();
    }
    mll operator/(const mll& a) const {
        mll res(*this);
        return res/=a;
    }

    friend ostream& operator<<(ostream& os, const mll& m){
        os << m.x;
        return os;
    }
};


#pragma endregion

V<ll> comp(V<ll> a){
    int n = SIZE(a);
    map<ll, ll> mp;
    rep(i, n) mp[a[i]] = 0;
    ll id = 1;
    for(auto&& p : mp) p.second = id++;
    FORA(i, mp){
        cout << i.first << "->" << i.second << endl;
    }
    cout << endl;
    rep(i, n) a[i] = mp[a[i]];
    return a;
}

int main(){    
    ll h, w, n; cin >> h >> w >> n;
    V<ll> a(n), b(n);
    rep(i, n){
        cin >> a[i] >> b[i];
    }
    a = comp(a); b = comp(b);
    rep(i, n){
        printf("%d %d\n", a[i], b[i]);
    }

    return 0;
}