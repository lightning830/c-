#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    ll tr[n][n];
    rep(i, n){
        rep(j, i+1){
            if(j == 0 || j == i){
                tr[i][j] = 1;
                cout << tr[i][j] << " ";
                continue;
            } 
            tr[i][j] = tr[i-1][j] + tr[i-1][j-1];
            cout << tr[i][j] << " ";
        }
        cout << endl;
    }

}