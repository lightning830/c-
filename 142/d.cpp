#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;


int main() {
    ll a, b; cin >> a >> b;
    ll halfa = sqrt(a), halfb = sqrt(b);
    // cout << "a=" << halfa << "b=" << halfb << endl;
    vector<ll> sa, sb;
    for(ll i = 2; i <= halfa; i++){//素因数分解
        if(a % i == 0) sa.push_back(i);
        while(a % i == 0) a /= i;
    }
    if(a > 1) sa.push_back(a);
    for(ll i = 2; i <= halfb; i++){
        if(b % i == 0) sb.push_back(i);
        while(b % i == 0) b /= i;
    }
    if(b > 1) sb.push_back(b);
    ll count = 1;
    // cout << sa.size() << " " << sb.size() << endl;
    for(auto &x: sa){
        for(auto &y: sb){
            if(x == y) count++;
            // cout << x << " " << y << endl;
        }
    }
    cout << count << endl;


    return 0;
}