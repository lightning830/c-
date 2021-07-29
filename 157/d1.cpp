#pragma region Macros
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define repd(i,n) for(ll i = n-1; i >= 0; i--)
#define FOR(i,a,b) for(ll i = a; i <= ll(b); i++)
#define FORD(i,a,b) for(ll i = a; i >= ll(b); i--)
#define FORA(i,I) for(const auto& i:I)
#define MOD 1000000007
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define V vector
//繰り上げ、繰り下げ
ll myceil(ll a,ll b){return (a+(b-1))/b;}
ll myfloor(ll a,ll b){return a/b;}
//最大値、最小値を更新
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a, b);}

map<string, ll> memo;
const int INF = 1001001001;
const ll LINF = 1e18;
#pragma endregion

struct UnionFind
{
    vector<int> d;
    UnionFind(int n = 0): d(n, -1){}
    int find(int x){//根にいる人を返す関数<0
        if(d[x] < 0) return x; //根にいる人
        return d[x] = find(d[x]);
    }

    bool unite(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return false;
        if(d[x] > d[y]) swap(x, y);//xが小さいなら。
        //dはつながっている人が格納されていて、
        //-なら自分含めた頂点数でその人が根。
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y){return find(x) == find(y);}
    int size(int x){return -d[find(x)];}
};


int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    UnionFind uf(n);
    V<ll> f(n, 0);
    V<V<ll>> bad(n);
    rep(i, m){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        f[a]++;
        f[b]++;
        uf.unite(a, b);
    }
    rep(i, k){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        bad[a].push_back(b);
        bad[b].push_back(a);
    }
    // cout << "now" << endl;
    rep(i, n){
        ll ans = uf.size(i)-1-f[i];
        // cout << "ans " << ans << endl;
        for(auto &&x : bad[i]){
            // cout << "x " << x << "i " << uf.find(i) << "x " << uf.find(x) <<  endl;
            if(uf.find(i) == uf.find(x)) ans--;
        }
        cout << ans << endl;
    }

    // cout << ans << endl;
    return 0;
}