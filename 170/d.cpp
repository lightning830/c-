#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

const int M = 1000005;
int main() {
    int n; cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    vector<int> cnt(M, 0);
    rep(i, n){
        if(cnt[a[i]] != 0){
            cnt[a[i]]++;
            continue;//a[i]かその約数は既に配列に加算しているためやる必要はない
        }
        for(int j = a[i]; j < M; j+=a[i]) cnt[j]++;
    }

    int ans = 0;
    rep(i, n){
        if(cnt[a[i]] == 1) ans++;
    }
    cout << ans << endl;

    return 0;
}