#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n , k;
    cin >> n >> k;
    int d[k];
    int a[k][n];
    vector<int> hito(n, 0);
    rep(i, k){
        cin >> d[i];
        rep(j, d[i]){
            cin >> a[i][j];
            hito[a[i][j]-1]++;
        }
    }
    int num = 0;
    rep(i, n){
        // cout << i << " " << hito[i] << endl;
        if(hito[i] == 0){
            num++;
        } 
    }
    cout << num << endl;

}