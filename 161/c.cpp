#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    ll ans = n%k;
    while(1){
        if(abs(ans - k) < ans){
            ans = abs(ans - k);
        }else break;
    }
    cout << ans << endl;

}