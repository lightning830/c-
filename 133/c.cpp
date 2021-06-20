#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int l, r;
    cin >> l >> r;
    int ans = INF;
    if(l - r > 2019){
        cout << 0 << endl;
        return 0;
    }
    for(int i = l; i < r; i++){
        for(int j = i+1; j <= r; j++){
            int ii = i % 2019;
            int jj = j % 2019;
            ans = min(ans, ii*jj % 2019);
            if(ans == 0) break;
        }
        if(ans == 0) break;
    }
    cout << ans % 2019 << endl;
    return 0;
}