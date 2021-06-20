#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll ans = 0;
    if(a < k){
        ans += a;
        if(b < k-a){
            ans -= k-a-b;
        }
    }else{
        ans += k;
    }
    cout << ans << endl;
}