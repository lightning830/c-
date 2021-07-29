#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

vector<ll> fac(300001); //n!(mod MOD)
vector<ll> ifac(300001); //k!^{MOD-2} (mod MOD)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod MOD) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

int main()
{
    int n, k;
    cin >> n >> k;

    //大した量ではないので，先にfax[i]とifax[i]を全て計算しておく
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % MOD; // n!(mod MOD)
        ifac[i+1] = ifac[i]*mpow(i+1, MOD-2) % MOD; // k!^{MOD-2} (mod MOD) ←累乗にmpowを採用
    }

    ll ans=0;
    ans = comb(n, k)%MOD;
    cout << ans << endl;
    return 0;
}