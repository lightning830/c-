#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    rep(i, n) cout << a[i] << endl;
    ll ans = 0;
    int dd = 0;
    rep(i, n/2){
        ans += a[i+dd];
        cout << "+" << a[i+dd] << endl;
        dd++;
    } 
    cout << ans << endl;
}
