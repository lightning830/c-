#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n; cin >> n;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    int ans = 0;
    sort(l.begin(), l.end());
    rep(b, n)rep(a, b){
        int ab = l[a] + l[b];
        int right = lower_bound(l.begin(), l.end(), ab) - l.begin();
        int left = b+1;
        ans += max(0, right-left);
    }
    cout << ans << endl;

    return 0;
}