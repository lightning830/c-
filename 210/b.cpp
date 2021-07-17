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


int main() {
    ll n; cin >> n;
    string s; cin >> s;
    int x;
    rep(i, SIZE(s)){
        if(s[i] == '1'){
            x = i;
            break;
        }
    }
    if(x % 2)cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;

    // cout << ans << endl;
    return 0;
}