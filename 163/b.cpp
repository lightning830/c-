#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    int a[m];
    int max = 0;
    rep(i, m){
        cin >> a[i];
        max += a[i];
    }
    cout << (n - max >= 0? n-max: -1) << endl;

}