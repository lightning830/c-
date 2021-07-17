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

//費用は式変形をして、a[i][j]+c*(i+j) + a[i'][j']-c*(i'+j')で求められる。
// 全ての点で(i', j')を決めて、そのときの費用の最小値を探索していく。
// ちなみに、左上とかはi'+j'=0+0で、1+1にならないから変に見えるが、c*(i+j)-c*(i'+j') = c*(i+1+j+1)-c*(i'+1+j'+1)なので問題ない。

// 場合分けで
// (1) パートナーである(i, j)が(i', j')より左上にいる場合
// (2) 左下にいる場合
// の二通りが考えられるが、配列を上下逆転して同じことをすればよいだけ。以下(1)について書く

// (i', j')が決まったとき、パートナー(i, j)はそれより左上なのだから、その範囲で最も小さいa[i'][j']-c*(i'+j')がわかればよい。
// そうすれば(i', j')での最小費用は上の式から足し算ですぐに求められる。

// どうするかというと
// d[i][j] = (i, j)までで最小のa[i][j]-c*(i+j)の値、ただし自分自身(i, j)は除く。として左上から求めていけばいい
// わざわざ別でループを回さなくても、(i',j')の左上をみるので同時に求められる。よって計算量HW
int main() {
    ll h, w, c;
    cin >> h >> w >> c;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, h)rep(j, w) cin >> a[i][j];

    ll ans = LINF;
    rep(_, 2){//上下反転バージョン
        vector<vector<ll>> d(h, vector<ll>(w, LINF));
        rep(i, h)rep(j, w){//i',j'のこと。
            // d[i][i] = (i, j)までで最小のa[i][j]-c*(i+j)の値、ただし自分自身(i, j)は除く

            // 上と下をみて(i,j)までの最小値をdにいれる。ただ、(i, j)は入れない、処理が終わった後に追加する。
            if(i) d[i][j] = min(d[i][j], d[i-1][j]);
            if(j) d[i][j] = min(d[i][j], d[i][j-1]);
            
            // (i,j)のときの最小の費用の計算、最小値更新
            ans = min(ans, a[i][j]+(i+j)*c+d[i][j]);
            // 自分自身はパートナーにいれてはいけないから、ansを出してから最後にdに追加
            // ここで最初に(0,0)のときのdが求まり、次に(0,1)は、(0,0)と(0,1)の小さいほうが入り、、と続く
            d[i][j] = min(d[i][j], a[i][j]-(i+j)*c);
        }
        reverse(ALL(a));
    }
    cout << ans << endl;
    return 0;
}