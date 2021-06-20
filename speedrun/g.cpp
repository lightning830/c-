#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    string s;
    rep(i, n){
        int a;
        cin >> a;
        s += to_string(a);
    }
    // rep(i, s.size()){
    //     cout << i << "=" << s[i] << endl;
    // }

    ll x = 0;
    rep(i, s.size()){
        x = (x*10 + (s[i] - '0')) % mod;
    }

    cout << x << endl;
}