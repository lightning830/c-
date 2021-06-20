#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    ll a, b, n;
    cin >> a >> b >> n;

    ll ans = 0;
    for(int i = n; i >= n - b/a-1; i++){
        if((a*i/b) - a*(i/b) > ans){
            ans = (a*i/b) - a*(i/b);
        }
    }
    cout << ans << endl;
}