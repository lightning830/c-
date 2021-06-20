#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    ll x;
    cin >> x;
    ll now = 100;
    ll n = 0;
    while(1){
        now += now*0.01;
        n++;
        if(x <= now){
            // cout << x << " " << now << endl;
            cout << n << endl;
            return 0;
        } 
    }
}