#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int gcd3(int a, int b, int c){
    return gcd(gcd(a,b),c);
}

int main() {
    int k; cin >> k;
    ll ans = 0;
    rep(i, k)rep(j, k)rep(l, k){
        ans += gcd3(i+1, j+1, l+1);
    }
    cout << ans << endl;
}
