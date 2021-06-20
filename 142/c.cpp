#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;


int main() {
    int n; cin >> n;
    vector<int> d(n,0);
    int a[n];
    rep(i, n){
        int x; cin >> a[i];
        x = a[i];
        d[a[i]-1] = i+1;
    }
    rep(i, n){
        cout << d[i] << " ";
    }
    cout << endl;
    return 0;
}