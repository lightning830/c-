#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    ll n; cin >> n;
    ll min = n-1;
    for(int i = 1; i <= sqrt(n)+1; i++){
        ll a = n / i;
        // cout << a << " " << i << " " << a*i << endl;
        if(a*i == n){
            ll tmp = (i-1)+(a-1);
            if(tmp < min) min = tmp;
            // cout << i-1 << " " << a-1 << endl;
        } 
    }
    cout << min << endl;
}