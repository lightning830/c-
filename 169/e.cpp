#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n; cin >> n;
    vector<int> ls(n), rs(n);
    rep(i, n){
        cin >> ls[i] >> rs[i];
    }
    sort(ls.begin(), ls.end());
    sort(rs.begin(), rs.end());
    int ans = 0;
    int l, r;
    if(n%2 == 1){
        l = ls[n/2];
        r = rs[n/2];
        ans = r-l+1;
    }else{
        l = ls[n/2-1]+ls[n/2];
        r = rs[n/2-1]+rs[n/2];
        ans = r-l+1;
    }
    cout << ans << endl;

    return 0;
}