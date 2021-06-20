#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n; cin >> n;
    int a[n];
    vector<int> buka(n, 0);
    rep(i, n-1){
        cin >> a[i];
        buka[a[i]-1]++;
    } 
    rep(i, n) cout << buka[i] << endl;
    

}