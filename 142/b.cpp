#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n, k;
    cin >> n >> k;
    int h[n];
    rep(i, n) cin >> h[i];
    int num = 0;
    rep(i, n){
        if(h[i] >= k) num++;
    }
    cout << num << endl;

    return 0;
}