#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n; double m;
    cin >> n >> m;
    int a[n];
    rep(i, n) cin >> a[i];
    double max = 0;
    rep(i, n){
        max += a[i];
    }
    int ans = 0;
    rep(i, n){
        if(max/(4*m) <= a[i]) ans++;
    }
    cout << ((ans >= m)? "Yes": "No") << endl;

}