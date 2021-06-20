#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int re(int i, int n){
    if(i == n-1){
        
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> x(n, vector<int>(n));
    vector<vector<int>> y(n, vector<int>(n));
    rep(i, n){
        cin >> a[i];
        rep(j, a[i]){
            cin >> x[i][j] >> y[i][j];
        }
    }




}