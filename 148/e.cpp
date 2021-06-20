#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    if(n%2==0){
        ll m = 10;
        ll ans = 0;
        while(1){
            if(m > n) break;
            ans += n/m;
            // cout << n/m << endl;
            m*=5;
        }
        cout << ans << endl;
    }else cout << 0 << endl;

}