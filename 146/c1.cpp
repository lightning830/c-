#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    ll l = 0, r = 1e9+1;
    auto keta = [&](ll c){
        int res = 0;
        while(c){
            c /= 10;
            res++;
        }
        return res;
    };
    auto f = [&](ll c){
        return a*c + b*keta(c);
    };
    while(r-l > 1){
        ll c = (l+r)/2;
        if(f(c) <= x) l = c;
        else r = c;
    }
    cout << l << endl;
    return 0;

}