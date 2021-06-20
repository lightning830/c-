#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int x[5];
    rep(i, 5) cin >> x[i];
    rep(i, 5){
        if(i+1 != x[i]){
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}