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

// k個までmapで種類数えて、k以上からは最初の数を除き、新たな数を追加する。
int main() {
    ll n, k;
    cin >> n >> k;
    ll c[n];
    map<ll, ll> m;
    rep(i, n){
        cin >> c[i];
    } 
    ll ans = 0;
    ll s = 0;//現在の最大値
    rep(i, n){
        // 追加
        if(m[c[i]] == 0) s++;
        m[c[i]]++;
        if(i >= k){
            // k以上からは先頭を削除
            if(m[c[i-k]] > 0) m[c[i-k]]--;
            // 削除して種類がなくなったら最大値減らす
            if(m[c[i-k]] == 0) s--;
        }
        chmax(ans, s);

    }
    cout << ans << endl;
    return 0;
}